#include<string>
#include<vector>
#include <sstream>
#include <cmath>
#include<iostream>

class Organism { 
    double mutation_prob = 0.1;
    int resource = 0;
    int fitness = 0;
    
    int num_starting_ones = 5;
    int genome_length=10;
    std::vector<int> genome;

    public:
        Organism(int genome_length_= 10, double mutation_prob_ = 0.1, int num_starting_ones_ = 5) : genome_length(genome_length_), 
        mutation_prob(mutation_prob_), num_starting_ones(num_starting_ones_) { initialize_genome();} 

        Organism( double mutation_prob_, int num_starting_ones_) : mutation_prob(mutation_prob_), num_starting_ones(num_starting_ones_) {initialize_genome();}
        
        int coop_prob = 0;
        //methods
        Organism reproduce();
        int get_fitness();
        void calc_fitness();
        bool update();
        void add_resource(int);
        void print_genome( );
        void calc_cooperation_prob();
        std::vector<int> initialize_genome();

        //getters
        std::vector<int> genome_() const {return genome;}
        int resource_() const {return resource;}
        int fitness_() const {return fitness;}
};

std::vector<int> Organism::initialize_genome( ) {
        genome.resize(genome_length);
        for( int i = 0; i < num_starting_ones; ++i)
            genome[i] = 1;
        for( int i = 0; i < 10-num_starting_ones; ++i)
            genome[i] = 0;
    return genome;
}


Organism Organism::reproduce() {  
    resource -=7;  
    Organism child = Organism();

    child.genome = genome;

    for ( int i  = 0; i < genome.size(); ++i )  // parent genome 
    {
        double prob = ( (double) rand() / (RAND_MAX)) ;
        if ( mutation_prob > prob ) 
        {
            if ( genome.at(i) == 0 )
                child.genome.at(i) = 1;
            else 
                child.genome.at(i) = 0;
        }
    }
    return child;

}

void Organism::print_genome( ) {
    std::cout << "[ " ;
    for ( int i = 0; i < static_cast<int>(genome.size()); ++i)
        std::cout << genome[i] << " ";
    std::cout << "]" << std::endl;
}

void Organism::calc_fitness() {
    for ( int bit : genome )
    {
        if ( bit == 1)
            ++fitness;
    }
}

bool Organism::update() {
    if( coop_prob >  5) { // compare to a random int?
        resource -=1;
        return true;
    }
    else {
        resource +=1;
        return false;
    }
}

void Organism::calc_cooperation_prob() {
    for( int bit : genome ) 
    {
        if( bit == 1)
            coop_prob +=1;
    }
    coop_prob /= static_cast<int>(genome.size());
}

void Organism::add_resource(int value) {
    resource += value;
}