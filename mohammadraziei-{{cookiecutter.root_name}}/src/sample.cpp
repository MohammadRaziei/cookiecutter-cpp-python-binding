#include "sample.h"

Sample::Sample(int var) : var(var) {}

Sample Sample::create_sample(int var) {
    return Sample(var);
}

int Sample::get_var() const {
    return var;
}

void Sample::set_var(int var){
    this->var = var;
}

std::string Sample::str() const{
    return std::to_string(var);
}