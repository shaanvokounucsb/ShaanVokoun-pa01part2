// ============================================================================
// CS32 P01 Part 2: the growth-factor experiment
//
// Implement measure_growth below. Then run   make experiment && ./experiment
// to see your results as a table.
// ============================================================================

#include "growth_experiment.h"
#include "Vector.h"

// Sets Vector<int>::growth_factor to factor, then push_backs n ints into an
// empty Vector<int>, watching what happens, and returns the GrowthStats (see
// growth_experiment.h for what each field means). Before returning, puts
// growth_factor back to the value it had when measure_growth was called.
//
// Measure by watching a real Vector<int>: push_back the elements one at a time
// and use size() and capacity() to see when the buffer grows and how many
// elements it had to copy. Do not compute the answers from the growth formula
// alone.
#include <cstddef>

GrowthData measure_growth(double factor, std::size_t n) {
    double original_factor = Vector<int>::growth_factor;
    
    Vector<int>::growth_factor = factor;
    
    Vector<int> v;
    GrowthData data;
    data.reallocations = 0;
    data.elements_copied = 0;
    data.final_capacity = 0;
    
    std::size_t current_capacity = v.capacity();
    
    for (std::size_t i = 0; i < n; ++i) {
        v.push_back(1); 
        
        if (v.capacity() != current_capacity) {
            data.reallocations++;
            data.elements_copied += current_capacity;
            current_capacity = v.capacity();
        }
    }
    
    data.final_capacity = v.capacity();
    Vector<int>::growth_factor = original_factor;
    
    return data;
}
