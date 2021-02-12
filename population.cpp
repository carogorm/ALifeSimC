#include<string>
#include<vector>
#include <sstream>
#include <cmath>
#include<iostream>
#include<algorithm>
#include<random>

#include "organism.cpp"


class Population {
    // data members
    int pop_size=50;
    int reproduction_threshold=7;
    double population_fitness=0.0;
    double mutation_prob = 0.1;
    int num_cooperators = 30;
    int num_partials = 10;
    int num_defectors = 10;
    double mean_coop_prob = 0.0;
    std::vector<Organism> organism_population; 
    std::vector<Organism> population_of_offspring; 
    
    // methods
    public:
        void update_population();
        void calculate_mean_fitness();
        double calc_mean_cooperation();
        std::vector<Organism> create_population(int pop_size);

        //constructor
        Population(int pop_size_=50, int reproduction_threshold_=15) : reproduction_threshold(reproduction_threshold_), pop_size(pop_size_) {} ;

        // getters 
        double population_fitness_() const {return population_fitness;}
};

std::vector<Organism> Population::create_population(int pop_size) {
    organism_population.resize(pop_size);
    for( int i = 0; i < num_cooperators; ++i) {
        Organism org = Organism(mutation_prob,10);
        organism_population.at(i) = org;
    }
    for( int i = 0; i < num_partials; ++i) {
        Organism org = Organism(mutation_prob,5);
        organism_population.at(i) = org;
    }
    for( int i = 0; i < num_defectors; ++i) {
        Organism org = Organism(mutation_prob,0);
        organism_population.at(i) = org;
    }
    return organism_population;
}

void Population::update_population() {
    for( int i = 0; i < static_cast<int>(organism_population.size()); ++i ) 
    {
        Organism & org = organism_population.at(i);
        org.calc_fitness();
        org.update();
        if (org.resource_() > reproduction_threshold)
        {
            Organism child = org.reproduce();
            child.initialize_genome();
            population_of_offspring.push_back(child);
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(organism_population.begin(), organism_population.end(), g );

    organism_population.erase( organism_population.begin(), organism_population.begin()+static_cast<int>(population_of_offspring.size()));

    for ( Organism child : population_of_offspring )
        organism_population.push_back(child);
    population_of_offspring.clear(); 
}

void Population::calculate_mean_fitness() {
    population_fitness = 0.0;
    for(Organism org : organism_population )
    {   
        org.calc_fitness();
        population_fitness += org.fitness_();
    }
    population_fitness /= static_cast<int>(organism_population.size());
}

double Population::calc_mean_cooperation() {
    for( Organism org : organism_population ) 
        mean_coop_prob += org.coop_prob;
    mean_coop_prob /= static_cast<int>(organism_population.size());
    return mean_coop_prob;
}