#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
using namespace std::chrono;

/**
 * Class used to hold marbles with varying modifiers.
 * 
 * Inherits from std::vector to minimize passing through functions.
 * Probably should have just used a container.
 * https://stackoverflow.com/questions/39016893/list-inheritance-in-c
 * 
 * @tparam T    Type of modifier to use.
 */ 
template<typename T>
class MarbleBag: public std::vector<T>{
public: 
    /**
     * Adds a list of modifiers a stored marble can have.
     * 
     * @param inputModifiers    The list of modifiers.
     */ 
    void assign_legal_modifiers(std::vector<T> inputModifiers){
        storedLegalModifiers = inputModifiers;
    }
    /**
     * Remove a random marble from the bag.
     * 
     * @return  The marble removed from the bag. Returns NULL if no marbles in bag.
     */ 
    T pop_rand(){
        if(this->size() < 1)
            return NULL;
        int indexToPop = lazy_random(this->size());
        T poppedValue = this->at(indexToPop);
        this->erase(this->begin() + indexToPop);
        return poppedValue;
    }
    /**
     * Add a marble to the bag while verifying it can be added.
     * 
     * @param inputValue    The modifier the marble will have.
     * @return              If the marble was able to be put in the bag.
     */ 
    int verify_push(T inputValue){
        if(verify_legality(inputValue, 1)){
            this->push_back(inputValue);
            return 1;
        }
        return 0;
    }
    /**
     * Adds many marbles to the bag while verifying they can be added.
     * 
     * @param inputValue    The modifier the marbles will have.
     * @param amount        How many marbles should be added.
     * @return              If the marbles were able to be put in the bag.
     */  
    int push_many(T inputValue, int amount){
        if(!verify_legality(inputValue, amount))
            return 0;
        for(int i = 0; i < amount; i++)
            this->push_back(inputValue);
        return 1;
    }

private:
    std::vector<T> storedLegalModifiers; /** Vector to hold list of user-defined marble modifiers */
    /**
     * Randomly selects a value between zero and a max value minus one.
     * 
     * Had issues with C RNG in 133c, so I wrote a simple randomness function
     * to replace the given ones.
     * 
     * @param max   The highest value plus one the function could give.
     * @return      The random value calculated.
     */ 
    int lazy_random(size_t max){
        // Obtain the current time since the epoch in milliseconds
        // https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
        int epoch_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        ).count();
        // Return the remainder of the epoch time divided by the maximum value.
        return epoch_time % max;
    }
    /**
     * Verifies if the marble(s) can be put into the bag.
     * 
     * This function checks if the total amount will exceed the 1 million
     * limit, if the amount of marbles added is 0, or if the modifier is not in
     * the list of user-defined modifiers.
     * 
     * @param inputModifier The modifier to verify.
     * @param amount        The amount of marbles about to be added.
     * @return              If the marble(s) can be put in the bag.
     */
    int verify_legality(T inputModifier, int amount){
        int totalAmount = amount + this->size();
        if(totalAmount > 1000000)
            return 0;
        for(int i = 0; i < storedLegalModifiers.size(); i++){
            if(storedLegalModifiers.at(i) == inputModifier 
                and amount > 0){
                return 1;
            }  
        }
        return 0;
    }
};

int tests(){
    MarbleBag<char> bag;
    bag.assign_legal_modifiers({'r','g','b'});
    char out;
    int success = 1;

    /** Test 1: Place a marble in, take it out, and ensure it is the same marble. */
    bag.verify_push('r');
    out = bag.pop_rand();
    if(out != 'r')
        success = 0;
    
    bag.verify_push('g');
    out = bag.pop_rand();
    if(out != 'g')
        success = 0;

    bag.verify_push('b');
    out = bag.pop_rand();
    if(out != 'b')
        success = 0;

    /** Test 2: Place in 5 marbles, then take them out. */
    std::vector<char> testMarbles = {'b','b','g','r','r'};
    std::vector<char> testMarblesOut;
    // Sort from https://www.cplusplus.com/reference/algorithm/sort/
    std::sort(testMarbles.begin(), testMarbles.begin() + 5);
    bag.verify_push(testMarbles.at(4));
    bag.verify_push(testMarbles.at(3));
    bag.verify_push(testMarbles.at(2));
    bag.verify_push(testMarbles.at(1));
    bag.verify_push(testMarbles.at(0));
    testMarblesOut.push_back(bag.pop_rand());
    testMarblesOut.push_back(bag.pop_rand());
    testMarblesOut.push_back(bag.pop_rand());
    testMarblesOut.push_back(bag.pop_rand());
    testMarblesOut.push_back(bag.pop_rand());
    std::sort(testMarblesOut.begin(), testMarblesOut.begin() + 5);
    if(testMarbles != testMarblesOut)
        success = 0;

    /** Test 3: Ensure that taking a marble out of the bag is not allowed. */
    out = bag.pop_rand();
    if(out != NULL)
        success = 0;

    /** Test 4: Ensure the program will not add marbles if amount is larger than
     * the 1 million limit. */
    out = bag.push_many('r', 1000001);
    if(out != 0)
        success = 0;

    out = bag.push_many('r', 1000000);
    if(out != 1)
        success = 0;

    out = bag.push_many('r', 1);
    if(out != 0)
        success = 0;

    return success;
}

int main(){
    printf("Test Output: %d\n",tests());
    return 0;
}