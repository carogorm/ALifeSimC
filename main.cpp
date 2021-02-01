#include <iostream>

#include "alifesim.cpp"

int main() 
{
  int my_pop_size = 50;
  int my_iterations = 50;
  ALifeSim my_alife_sim = ALifeSim(my_pop_size, my_iterations );

  srand((unsigned) time(0));

  Organism parent = Organism();
  parent.initialize_genome();
    
  std::cout << "Parent: " ;
  parent.print_genome();

  parent.calc_fitness();
  std::cout << "Fitness: " << parent.fitness_() << std::endl;
  parent.update();
  std::cout <<  "Resource is: "  << parent.resource_() << std::endl;
    
  Organism child = parent.reproduce();
  std::cout << "Child: ";
  child.print_genome();
  child.calc_fitness();
  std::cout << "Child fitness is: " << child.fitness_() << std::endl;
    
  std::cout << "Parent after reproducing: " ;
  parent.print_genome();
    

  Population my_pop = Population(); 
  my_pop.create_population(20);
  my_pop.calculate_mean_fitness();
  std::cout<< my_pop.population_fitness_() << std::endl;

  for( int i = 0; i < 50; ++i)
    my_pop.update_population();

  my_pop.calculate_mean_fitness();
  std::cout << my_pop.population_fitness_() << std::endl; 


}