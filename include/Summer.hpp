// Class for doing different kinds of summations
// on just unsigned integers

#include <future>
#include <numeric>
#include <mutex>

class Summer {
public:
    explicit Summer(unsigned int start_value):
            value_(start_value) { }
    
    unsigned int add_value(unsigned int value);
    
    template<typename C>
    unsigned int add_values(C values);
    
    template<typename C>
    std::future<unsigned int> add_values_async(C values);

    unsigned int get_current_value() const; 
    void reset_value();

private:
    std::mutex value_lock_;
    unsigned int value_;
};

// template methods must be defined in header file
// to avoid potentially weird linker errors


// Sum the given values and add it to the current value
// Return the final value
template<typename C>
unsigned int Summer::add_values(C values)
{
    auto temp = std::accumulate(values.begin(), values.end(), value_);

    std::lock_guard<std::mutex> lk(value_lock_);
    value_ = temp;
    return value_;
}

// Sum the given values asynchronously and return
// a future which will be populated with the final
// well when the job finishes
template<typename C>
std::future<unsigned int> Summer::add_values_async(C values) 
{
    return std::async(&Summer::add_values, this, values);
}
