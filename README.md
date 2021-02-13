## Artificial Life Simulator
####
Artificial life is used to study biological processes, such as evolution, through the use of computer simulations. ALifeSimPython is an artificial life simulator that uses digital evolution to create and study a population of organisms. 

This program is written in C++ and contains an ALifeSim class, Population class and Organism class. The ALifeSim class acts as the driver class, creating a population of organisms. The population contains organisms which are 10-bit genomes containing 1s and 0s. Their cooperation probability is determined by the number of 1s in their genome. When the population is updated, the organisms are updated. When an organism updates, if their cooperation probability is greater than some randomly-generated number, the organism's resource will decrease by 1 and the two organisms adjacent to it in the population will gain 4 to their resources. For each organism in the population, if their resource is greater than the reproduction threshold (specified by the user), that organism will reproduce and their offspring will be added to the population. The population then randomly removes organisms from the population to keep the size of the population constant. The mean cooperation probability can be calculated for the population to see how it changes over time with evolutions. 
####
Created by Caroline Gormely 
