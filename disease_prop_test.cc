#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;
using std::cout;
using std::endl;

class Person {
	public:
		int sickday;
		int state = 0;

		int get_state() {
			return state;
		}

		string status_string() {
			// Return person's state as a string using Switch statement
			switch(state) {
				case 0 : 
					return "susceptible";
					break;
				case -1 :
					return "recovered";
					break;
				case -2 :
					return "vaccinated";
					break;
				default :
					string sickstatement = "sick (" 
						+ to_string(state) + " to go)";
					return sickstatement;
					break;
				}
		}

		void update() { 
			if (is_stable() == false) {
			// Next day, the sick person has one less sick day left
				state = state - 1;

				if (state == 0) {
					state = -1; //recovered
				}
			}
		}

		bool is_stable() {
			if (state > 0) {
				// Person is sick
				return false;
			}
			else {
				// Person is recovered
				return true;
			}

		}
		
		void infect(int sickday) {
			if (state==0) {
				state = sickday;
			};
		}
	
		void vaccinate() {
			if (state==0) {
				state = -2;
			};
		}

};

class Population {
	public:
		int myPopsize = 10;
		int mySickday;
		vector<Person> myPop;
		vector<int> count;		
		float transfer_prob;
		float bad_luck;
		int max_interaction = 6; 
		float percent_vaccine;

		Population(int popsize, int sickday, int interact) {
			myPopsize = popsize;
			mySickday = sickday;
			max_interaction = interact;
			
			cout << "Population size: " << myPopsize << endl;
			cout << "Infection period: " << mySickday << endl;
			cout << "Maximum interaction: " << max_interaction << endl;
	
			// Add a variable of class Person to the vector myPop
			for (int i = 0; i < myPopsize; i++) {
				Person myPerson;
				myPop.push_back(myPerson);
				count.push_back(i);
			} 
		}
		
		void set_probability_of_transfer(float probability) {
			transfer_prob = probability;
		}
				
		void random_infection() {
			// Randomly infecting one person in myPop
			int infected_person = rand() % myPopsize;
			myPop.at(infected_person).infect(mySickday);		
		}

		int count_infected() {
			int j = 0;

			// Count how many people are infected/sick in myPop
			for (auto i : count) {
				if (myPop.at(i).is_stable()) {}
				else {
					j = j + 1;
				}
			}
 
			return j;		
		}

		// Update + disease spread
		void update() {
			int num_sick = count_infected();
			for (auto i : count) {
				myPop.at(i).update();
			}
		
			//cout << "bad luck = ";
			//cout << "# interactions: ";

		// Each sick person can infect another random person (with up to max_interaction)
			if (max_interaction == 0) {} //if no interaction, there's no spread of disease
			else {
				for (int j = 0; j < num_sick; j++) {
					int interaction = rand() % max_interaction + 1;
				
					for (int k = 0; k < interaction; k++) {
						bad_luck = (float) rand()/(float)RAND_MAX;
						if (bad_luck > transfer_prob) {} //lucky, nothing happens
						else { //unlucky, one rand person infected if susceptible
							random_infection();
						}
					}
				}
			}
		}

		void vaccinate(float percent_vaccine) {
			int num_vaccine = percent_vaccine*myPopsize;
			cout << "Number of vaccinated = " << num_vaccine << endl;

			for (int k = 0; k < num_vaccine; k++) {
				int vaccinated_person = rand() % myPopsize;
				myPop.at(vaccinated_person).vaccinate();
			}		
		}	

};

int main() {
	// Person joe;
	
	int step = 1;
	
	srand((unsigned)time(0));
	
	int pop_size = 40000;
	int infection_period = 14;
	int maxinteraction = 10;
	float spread_prob = 0.1;
	float percent_vaccinated = 0.2;

	Population A(pop_size,infection_period,maxinteraction);
	A.random_infection();
	A.set_probability_of_transfer(spread_prob);
	A.vaccinate(percent_vaccinated);	
	cout << endl;
	
	cout << "Num_day ," << "Num_sick ," << endl;

	for ( ; ; step++) {
		//cout << "On day " << step << " #sick: " << A.count_infected() << endl;
		cout << step << " , " << A.count_infected() << endl;

		/*
		cout << "\nOn day " << step << " #sick: " << A.count_infected() << " : ";
		// Displaying the state of each Person in Population A 
		for (int i = 0; i < pop_size; i++) {
			cout << A.myPop.at(i).get_state() << " ";
		}
		cout << endl;
		*/
	
		A.update();

		// When #sick = 0, our simulation is done. (next day after update)
		if (A.count_infected() == 0) {
			step = step + 1;
			cout << step << " , " << A.count_infected() << endl;

			// cout << "On day " << step << " #sick: " << A.count_infected();
			/*
  			cout << "\nOn day " << step << " #sick: " << A.count_infected() << " : ";
			for (auto i : A.count) {
				cout << A.myPop.at(i).get_state() << " ";
			}
			*/
			cout << endl;
			break;
		}
	}

	return 0;

}	
