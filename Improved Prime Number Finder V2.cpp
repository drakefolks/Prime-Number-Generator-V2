#include<iostream> //for input output
#include<fstream> //for reading and writing to and from files
#include<vector> // for vectors
#include<algorithm> //for set difference to compare generated primes to correct prime files
#include<cmath>
#include<math.h>

using namespace std;

int main()
{
	int high = 0;
	int low = 0;
	
	vector<int>primeNum;
	bool prime = true;

	cout << "Please enter your starting number\n";
	cin >> low;
	cout << "Please enter the number of prime numbers you want to find up to\n";
	cin >> high;

	
	int x = 2;
	//while loop to go from high to low
	while (low <= high)
	{
		float low_root = (floor)(sqrt(low));
		int low_root_int = low_root;

		//for loop that goes from 2 to sqare root of low, testing if low divides into x.
		//If it does, it is not prime.
			for (int x = 2; x <= low_root_int; ++x)
			{
			
				if (low % x == 0)
				{
					prime = false;
					break;
				}

				else
				{
					prime = true;

				}

			}

			//if low is one there is no spoon
			//if low is prime, stores to vector and outputs the prime value
			if (prime)
			{	
				if (low == 1)
				{
					cout << low << " is not prime, the spoon does not exist.\n";
					primeNum.clear();
				}

				else
				{
					cout << low << " is prime\n";
					primeNum.push_back(low); //if it is prime and not one, gets stored into vector
				}
				
			}
			low++;
	}

	ofstream primeNumFile;
	primeNumFile.open("prime nums.txt"); //opening prime nums.txt
	for (const auto& e : primeNum) primeNumFile << e << "\n"; //writing each primeNum value to primeNumFile on a differnt line
	primeNumFile.close();


		//file checking	
		ifstream File1;
		File1.open("prime nums.txt"); //openeing prime nums txt
		istream_iterator<double> start1(File1), end; //creating start1 iterator
		vector<double> numbers1(start1, end); //creating numbers1 vector, and writing all values to it
		cout << "\nRead " << numbers1.size() << " numbers from generated primes" << endl; //outputting how many primes were found


		{
			ifstream File2;
			File2.open("prime check.txt");
			istream_iterator<double> start2(File2), end;
			vector<double> numbers2(start2, end);
			cout << "\nRead " << numbers2.size() << " numbers from given primes" << endl;

			vector<int> result(2000000); //creating vector result
			vector<int>::iterator it, ls; //setting up iterator and vector to take difference of numbers1 and numbers2

			ls = set_difference(numbers1.begin(), numbers1.end(), numbers2.begin(), numbers2.end(), result.begin()); //taking difference of numbers1 and numbers2

			cout << "\nThe differnece is " << ls - result.begin() << " elements: " << endl; //calculating and outputting difference amount 

			for (it = result.begin(); it < ls; ++it) //outputting all elements that are differnt
				cout << " " << *it;
			cout << "\n";

			File1.close();
			File2.close();
		}
	
		
	return 0;
}