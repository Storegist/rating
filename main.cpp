#include <iostream>
#include <string>
#include <utility> // для std::swap(). Якщо у вас не підтримується C++11, то тоді #include <algorithm>
#include <fstream>



void sortArray(std::string *array, int *array2, int length)
{
	// Перебираємо кожний елемент масиву
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// smallestIndex - індекс найменшого елементу, який ми зустріли
		int smallestIndex = startIndex;
 
		// Шукаємо найменший елемент, який залишився в масиві (починаючи з startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Якщо поточний елемент менше нашого раніше знайденного елементу,
			if (array[currentIndex] < array[smallestIndex])
				// то тоді це нове найменше значення в цій ітерації
				smallestIndex = currentIndex;
		}
 
		// Змінюємо місцями наш початковий елемент зі знайденим найменшим елементом масиву
		std::swap(array[startIndex], array[smallestIndex]);
		std::swap(array2[startIndex], array2[smallestIndex]);
	}
}

void average(int *mark, int length){

	    int sum=0;

        for(int n=0; n <= length; ++n)
		{
             sum +=mark[n];
		}

		std::cout<<"Average score is: "<< sum/length <<'\n';
}


int main()
{
	std::cout << "How many names would you like to enter? ";
	int length;
	std::cin >> length;
 
	// create an array for names
	std::string *names = new std::string[length];

	// create an array for marks
	int *marks = new int[length];
 
	// ask user to enter names and marks
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::cin >> names[i];

	    std::cout << "Enter mark"<< ": ";
		std::cin >> marks[i];
		std::cout<<std::endl;

	}

    std::cout << "\nHere is what you entered:\n";

    // entered names and marks output to console
	for (int i = 0; i < length; ++i)
	{
		
		std::cout << names[i]<<" "<<marks[i];
		std::cout<<std::endl;
	}

		// Сортуємо масив
	sortArray(names, marks, length);
 
	std::cout << "\nHere is your sorted list:\n";

    for (int i = 0; i < length; ++i)
	std::cout << "Name #" << i + 1 << ": " << names[i] <<" "<<marks[i]<< '\n';


    std::cout << "\nLet's create a txt file and write the names and marks into it:\n";
     
	std::ofstream MyFile("filename.txt");
    
	for (int i = 0; i < length; ++i)
    MyFile<<"Name #" << i + 1 << ": " << names[i] <<" "<<marks[i]<< '\n';

    
 // Close the file
     MyFile.close();

	average(marks, length);



	delete[] names; // emptying memory
        names = 0; 

	delete[] marks; // emptying memory
        marks = 0; 		
 
	return 0;
}