#include "population.cpp"

class ALifeSim {
    // data members 
    int pop_size = 50;
    int num_iterations = 5;
    double mutation_prob = 0.1;
    int num_cooperators = 30;
    int num_partials = 10;
    int num_defectors = 10;
    Population pop;
    std::vector<double> mean_probability_scores;

    public:
        // methods 
        bool check_percents();
        void create_population();
        void evolve();
        // constructor 
        ALifeSim(int size, int iterations) : pop_size(size), num_iterations(iterations) {create_population();};

        ALifeSim(int size, int iterations, double mutation, int cooperators, int partials,
        int defectors) : pop_size(size), num_iterations(iterations), mutation_prob(mutation), 
        num_cooperators(cooperators), num_partials(partials), num_defectors(defectors) {create_population();};

};
void ALifeSim::create_population() {
    pop = Population(pop_size);
    evolve();
}


bool ALifeSim::check_percents() {
    if ( num_cooperators + num_partials + num_defectors != pop_size)
        return false;
    else
        return true;
    
}

void ALifeSim::evolve() {
    for( int i = 0; i < num_iterations; ++i) 
    {
        pop.update_population();
        mean_probability_scores.push_back( pop.calc_mean_cooperation() );

    }

}
