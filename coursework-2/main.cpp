#include "header.h"

void addBook() {
    //These chars control amount of characters that can be inputted
      char title[80];
      char author[60];
      char ISBN[13];
      char quantity[3];

      cin.ignore(); // Helped me to seperate the UI kept getting mixed up
      
      cout<<"Please Enter The Book's Title: "<<endl;
      cin.getline(title, 80);
      
      cout<<"Please Enter The Book's Author: "<<endl;
      cin.getline(author, 60);
      
      cout<<"Please Enter The Book's ISBN (International Standard Book Number)"<<endl;
      cin.getline(ISBN, 13);

      cout<<"Please Enter The Current Quantity In Stock: "<<endl;
      cin.getline(quantity, 3);

      for(int o = 0; o < cap; o++){ //checks if array is empty or not so nothing is left out
	if(bookTitle[o] == "\0"){
	  bookTitle[o] = title;
	  bookAuthor[o] = author;
	  bookISBN[o] = ISBN;
	  bookQuantity[o] = quantity;
	  break;  
	}
      }
}

void removeBook(string get) {
  int counter = 0;
   for(int o = 0; o < cap; o++){
     if(bookTitle[o] == get){
       counter++; //if counter doesnt go down the list that means no books exsist
       bookTitle[o] = "";
       bookAuthor[o] = "";
       bookISBN[o] = "";
       bookQuantity[o] = "";
       cout<< "Deleted" << endl;
       break;  
     }
   }
   if (counter == 0){ cout<<"There Are No Books That Currently Match That Title."<<endl; }
}



void  viewStock() {

    cout<<"Library Stock"<< endl;
    cout<<"========================================================================================="<<endl;
    cout<<"No.   Title                    Author                   ISBN                  Quantity"<<endl;
    cout<<"========================================================================================="<<endl;

    int counter = 0;

    for (int o = 0; o < cap; o++){                                // displays the strings in the array
      if(bookTitle[o] != "\0"){
	counter++;
	  cout<< counter<<"     "<<bookTitle[o]<<"             "<<bookAuthor[o]<<"              "<<bookISBN[o]<<"              "<<bookQuantity[o]<<endl;
      }
    }

    if (counter == 0){ cout<<"No Books Currently Inputted."<<endl; }
}

void searchBook(string get) {
  
  cout << "Books that match that name..." << endl;
  cout<<"========================================================================================="<<endl;

    int counter = 0;

    for (int o = 0; o < cap; o++){                                // displays the strings in the array
      if (bookTitle[o] == get){
	counter++;
        cout<<" "<< counter <<bookTitle[o]<<"             "<<bookAuthor[o]<<"              "<<bookISBN[o]<<"              "<<bookQuantity[o]<<endl;
	break;
      }	
    }

    if (counter == 0){ cout<<"No Books Currently Have this Title."<<endl; }
}

int main() {

    int userInput;
    string bookTitle;

    do{
      cout<<"========================================================================================="<<endl;
      cout << "Library System" << endl;
      cout << "Please Enter What youd Like To Do" << endl;
      cout<<"========================================================================================="<<endl;
      cout << "Add A Book...(Press 1)" << endl;
      cout << "Remove A Book...(Press 2)" << endl;
      cout << "Search for A Book...(Press 3)" << endl;
      cout << "View Book Stock...(Press 4)" << endl;
      cout << "Exit The System...(Press 5)" << endl;
      cout<<"========================================================================================="<<endl;
      cout<<"Enter A Number"<<endl;
      
      cin >> userInput;   
    
        switch (userInput) {
            //Add A Book
            case 1:
	      cout<<"========================================================================================="<<endl;	      
	      addBook();
	      break;

            //Remove A Book
            case 2:
	      cout<<"========================================================================================="<<endl;
	      cout<<"Delete A Book"<<endl;
	      cin.ignore();
	      getline(cin, bookTitle);
	      removeBook(bookTitle);
	      break;

            //Search for book
            case 3:
	      cout<<"========================================================================================="<<endl;
	      cout << "Search For A Book Using Title"<<endl;
	      cin.ignore();
	      getline(cin, bookTitle);
	      searchBook(bookTitle);
	      break;

	    //View for books
            case 4:
	      cout<<"========================================================================================="<<endl;
	      viewStock();
	      break;

	    //Exit System
            case 5:
	      cout << "You Have Now Exited The Library System." << endl;
	      exit(0);
	      break;
	}
     }while(userInput !=5); //If its not option 3 bring menu back and Close Switch
}//Closes Main
