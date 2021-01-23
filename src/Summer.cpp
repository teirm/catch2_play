// Class implementation for doing a variety of summations

#include <Summer.hpp>

// @brief Add a value to the current value of instance 
//
// @param[in]   value   value to add
//
// @return  final value held by instance
unsigned int Summer::add_value(unsigned int value)
{
    std::lock_guard<std::mutex> lk(value_lock_);
    value_ += value;
    return value_;
}

// @brief Return the current value of the instance
//
// @return value held by the instance
unsigned int Summer::get_current_value() const
{
    return value_;
}

// @brief Reset the value held by the instance
void Summer::reset_value()
{
    value_ = 0;
}
