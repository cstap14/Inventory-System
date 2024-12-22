//#include <iostream>
//#include "Paint.h"
#include "HighGloss.h"
#include "SemiGloss.h"
#include "Eggshell.h"
#include "Satin.h" //sussy
#include "Flat.h"


//#include <algorithm>
//#include <string>

//using namespace std;

//I am not using namespace because I vaguely remember from
//the random number mindtap that 'using namespace std' 
//caused me problems, so I had to use std:: to get things right
//If I'm wrong... better safe than sorry ig

using std::cout;
using std::cin;
using std::endl;
using std::system;
using std::string;


int printList1(bool&);
int printList2();
void validColors(string&);
bool glossLevel(float& gl);
void inputData(string&, float&);

const enum PaintType{FLAT = 1, EGGSHELL, SATIN, SEMIGLOSS, HIGHGLOSS};
//const enum Color { RED = 1, BLUE, PURPLE, GREY, BLACK, YELLLOW, GREEN };

int main()
{

    bool inFile = 1;
    std::random_device rdevice{};
    std::default_random_engine num{ rdevice() };
    string color, file;
    int count = 0, PL2;
    float numPaint;
    std::ofstream fout, ffout;
    std::ifstream fin;
    Paint* arr[7];

   // cout << "hi\a";

    /*for (unsigned int count = 1; count <= 25; count++)
    {
        std::cout << count << ". " << randomRealNum(num) << std::endl;

    }*/

    //std::uniform_int_distribution<unsigned int> randomRealNum{ 1, 50 };

    //float a = randomRealNum(num);
    //cout << a << endl;
    //a /= 10;
    //cout << a << endl;

    //system("pause");

    //std::cout << "Hello World!\n";
   // Paint* arr[7];

    //arr[0] = new Flat("RED", 2.3, 4);

    //cout << arr[0]->getColor() << endl << arr[0]->getGlossLevel() << endl << arr[0]->getNumPaint() << endl;

    for (int x = 0; x < 7; x++)
    {

        switch (printList1(inFile))
        {

            //count++;

        case FLAT:
        {

            std::uniform_int_distribution<unsigned int> randomRealNum{ 1, 50 };
            //int gloss;
            float gl = (float) randomRealNum(num) / 10;
            //gl = randomRealNum(num);

            inputData(color, numPaint);

            arr[x] = new Flat(color, gl, numPaint);


            //arr[x]->help();
            break;
        }

        case EGGSHELL:
        {

            std::uniform_int_distribution<unsigned int> randomRealNum{ 105, 250 };
            //int gloss;
            float gl = (float) randomRealNum(num) / 10;
            //gl = randomRealNum(num);

            inputData(color, numPaint);

            arr[x] = new Eggshell(color, gl, numPaint);

            //arr[x]->help();

            break;
        }

        case SATIN:
        {

            std::uniform_int_distribution<unsigned int> randomRealNum{ 255, 350 };
            //int gloss;
            float gl = (float) randomRealNum(num) / 10;
            //gl = randomRealNum(num);

            inputData(color, numPaint);

            arr[x] = new Satin(color, gl, numPaint);

            //arr[x]->help();

            break;
        }

        case SEMIGLOSS:
        {

            std::uniform_int_distribution<unsigned int> randomRealNum{ 355, 700 };
            //int gloss;
            float gl = (float) randomRealNum(num) / 10;
            //gl = randomRealNum(num);

            inputData(color, numPaint);

            arr[x] = new SemiGloss(color, gl, numPaint);
            //arr[x]->help();

            break;
        }

        case HIGHGLOSS:
        {

            std::uniform_int_distribution<unsigned int> randomRealNum{ 850, 950 };
            //int gloss;
            float gl = (float) randomRealNum(num) / 10;
            //gl = randomRealNum(num);

            inputData(color, numPaint);

            arr[x] = new HighGloss(color, gl, numPaint);
            //arr[x]->help();

            break;
        }

        case 6:

            float gl;

            cout << "Enter name of file that you intend to read in from (do not enter .txt): ";
            cin.ignore();
            getline(cin, file);

            fin.open(file + ".txt");

            while (!fin)
            {
                fin.clear();
                fin.close();

                cout << "File doesn't exist...\n\n";

                cout << "Enter name of file that you intend to read in from (do not enter .txt): ";
                cin >> file;

                fin.open(file + ".txt");

            }


            for (int y = 0; y < 7; y++)
            {
                fin >> color;
                fin >> numPaint;

                validColors(color);

                while (numPaint < 0 || !fin)
                {
                    fin.clear();
                    
                    cout << "Bad input\n\n";
                    cout << "How many cans of paint are present: ";
                    cin >> numPaint;
                }

                fin >> gl;
                //cout << gl;

                
                if (glossLevel(gl))
                {
                    //Cut from the glossLevel function, instead of returning true, it actually dynamically creates
                    //each object pending on the gloss level

                    if (gl >= 0.1 && gl <= 5)
                        arr[y] = new Flat(color, gl, numPaint);
                    else if (gl >= 10.5 && gl <= 25)
                        arr[y] = new Eggshell(color, gl, numPaint);
                    else if (gl >= 25.5 && gl <= 35)
                        arr[y] = new Satin(color, gl, numPaint);
                    else if (gl >= 35.5 && gl <= 70)
                        arr[y] = new SemiGloss(color, gl, numPaint);
                    else if (gl >= 85 && gl <= 95)
                        arr[y] = new HighGloss(color, gl, numPaint);
                }

            }

            x = 7;//Ends for loop
            fin.close();

            break;
        }


    }

    system("pause"); //Allows time to see messages in constructors being printed

    do
    {
        //system("pause");
        system("CLS");
        PL2 = printList2();

        cout << std::fixed << std::setprecision(2);

        switch (PL2)
        {
        case 1: //Adjust Inventory

            int input;

            cout << "#:" << std::setw(12) << "Paint Color" << std::setw(18) << "Number of Cans" << std::setw(18) << "Gloss Level(%)\n";

            for (int x = 0; x < 7; x++)
            {
                cout << x + 1 << std::setw(12) << arr[x]->getColor() << std::setw(18) << arr[x]->getNumPaint() << std::setw(18) << arr[x]->getGlossLevel() << endl;
            }

            cout << endl;

            cout << "Which set do you want to edit: ";
            cin >> input;
            input--;

            while (!cin || input < 0 || input > 6)
            {

                cin.clear();
                cin.ignore(123, '\n');

                cout << "Bad input...\n\n";

                cout << "#:" << std::setw(12) << "Paint Color" << std::setw(18) << "Number of Cans" << std::setw(18) << "Gloss Level(%)\n";

                for (int x = 0; x < 7; x++)
                {
                    cout << x + 1 << std::setw(12) << arr[x]->getColor() << std::setw(18) << arr[x]->getNumPaint() << std::setw(18) << arr[x]->getGlossLevel() << endl;
                }

                cout << "Which set do you want to edit: ";
                cin >> input;
                input--;
            }

            cout << "Enter the color: ";
            cin >> color;

            validColors(color);

            cout << "Enter amount of cans: ";
            cin >> numPaint;

            arr[input]->setColor(color);
            arr[input]->setNumPaint(numPaint);

            //std::uniform_int_distribution<unsigned int> randomRealNum{ 850, 950 };
            ////int gloss;
            //float gl = randomRealNum(num) / 10;

            //arr[input]



            system("pause");

            break;

        case 2: //View Help for each selection

            int help;
            cout << "#:" << std::setw(12) << "Paint Color" << std::setw(18) << "Number of Cans" << std::setw(18) << "Gloss Level(%)\n";

            for (int x = 0; x < 7; x++)
            {
                cout << x + 1 << std::setw(12) << arr[x]->getColor() << std::setw(18) << arr[x]->getNumPaint() << std::setw(18) << arr[x]->getGlossLevel() << endl;
            }

            cout << endl;

            cout << "I want help for #";
            cin >> help;

            while (!cin || help < 1 || help > 7)
            {
                cin.clear();
                cin.ignore(123, '\n');

                cout << "Error " << (cin ? "Input must be between 1 and 7 (inclusive)" : "No strings in an int input") << endl << endl;

                cout << "I want help for #";
                cin >> help;

            }

            arr[help-1]->help();

            cout << endl;
            system("pause");

            break;

        case 3: //View Inventory

            cout << "#:" << std::setw(12) << "Paint Color" << std::setw(18) << "Number of Cans" << std::setw(18) << "Gloss Level(%)\n";

            for (int x = 0; x < 7; x++)
            {
                cout << x + 1 << std::setw(12) << arr[x]->getColor() << std::setw(18) << arr[x]->getNumPaint() << std::setw(18) << arr[x]->getGlossLevel() << endl;
            }

            cout << endl;
            system("pause");

            break;

        case 4: //Print to file
        {
            string file;

            cout << "Enter name of file you would like to save to (do not enter .txt): ";
            cin.ignore();
            std::getline(cin, file);

            while (!cin)
            {
                cin.clear();
                cin.ignore(123, '\n');

                cout << "Error...\n\n";

                cout << "Enter name of file you would like to save to (do not enter .txt): ";
                cin >> file;

            }

            fout.open(file + ".txt");
            ffout.open(file + "INVT.txt");

            fout << "#:" << std::setw(12) << "Paint Color" << std::setw(18) << "Number of Cans" << std::setw(18) << "Gloss Level(%)\n";

            for (int x = 0; x < 7; x++)
            {
                fout << x + 1 << std::setw(12) << arr[x]->getColor() << std::setw(18) << arr[x]->getNumPaint() << std::setw(18) << arr[x]->getGlossLevel() << endl;
                ffout << arr[x]->getColor() << endl;
                ffout << arr[x]->getNumPaint() << endl;
                ffout << arr[x]->getGlossLevel() << endl;

            }

            cout << endl;
            system("pause");

            fout.close();
            ffout.close();

            break;
        }

        case 5:

            break;
        }

    } while (PL2 != 5);

    for (int x = 0; x < 7; x++)
    {
        delete arr[x];
    }

    cout << endl;

    system("pause");
    return 0;

}

int printList1(bool& inFile)
{
    int input, fiveOrSix = 6;

    if (!inFile)
        fiveOrSix = 5;

    cout << "(1) Flat Paint" << endl;
    cout << "(2) Eggshell Paint" << endl;
    cout << "(3) Satin Paint" << endl;
    cout << "(4) Semi-Gloss Paint" << endl;
    cout << "(5) High-Gloss Paint" << endl;

    if(inFile)
       cout << "(6) Load Inventory from file" << endl;

    cin >> input;

    while (!cin || input < 1 || input > fiveOrSix)
    {
        

        cout << "Error, " << (cin ? "Must be between 1 & " + fiveOrSix:"No text allowed in int inputs") << endl << endl;

        cin.clear();
        cin.ignore(123, '\n');
        
        cout << "(1) Flat Paint" << endl;
        cout << "(2) Eggshell Paint" << endl;
        cout << "(3) Satin Paint" << endl;
        cout << "(4) Semi-Gloss Paint" << endl;
        cout << "(5) High-Gloss Paint" << endl;

        if(inFile)
            cout << "(6) Load Inventory from file" << endl;

        cin >> input;

    }

    if (input != 6)
    {
        inFile = 0;
    }

    return input;

}


int printList2()
{

    int input;

    cout << "Please choose from the following options: \n";
    cout << "(1) Adjust Inventory" << endl;
    cout << "(2) View Help for Selection" << endl;
    cout << "(3) View Current Inventory" << endl;
    cout << "(4) Print Current Inventory to File" << endl;
    cout << "(5) Quit" << endl;
    //cout << "(6) Load Inventory from file" << endl;
    cin >> input;

    while (!cin || input < 1 || input > 5)
    {
        cin.clear();
        cin.ignore(123, '\n');

        cout << "Error, " << (cin ? "Must be between 1 & 5" : "No text allowed in int inputs") << endl << endl;

        cout << "Please choose from the following options: \n";
        cout << "(1) Adjust Inventory" << endl;
        cout << "(2) View Help for Selection" << endl;
        cout << "(3) View Current Inventory" << endl;
        cout << "(4) Print Current Inventory to File" << endl;
        cout << "(5) Quit" << endl;

        cin >> input;

    }

    return input;
}

//Recursive function that will exit iff the correct colors are inputted
void validColors(string& clr)
{
    transform(clr.begin(), clr.end(), clr.begin(), ::toupper);
    
    if (clr == "RED")
        return;
    else if (clr == "BLUE")
        return;
    else if (clr == "PURPLE")
        return;
    else if (clr == "GRAY")
        return;
    else if (clr == "BLACK")
        return;
    else if (clr == "YELLOW")
        return;
    else if (clr == "GREEN")
        return;
    else if (clr == "TEAL")
        return;

    cout << "Color " << clr << " not available to choose...\n\nEnter Color : ";
    cin >> clr;

    while (!cin)
    {

        cin.clear();
        cin.ignore(123, '\n');

        cout << "Bad input...\n\n";
        cout << "Color " << clr << " not available to choose...\n\nEnter Color : ";
        cin >> clr;
    }

    validColors(clr);
}

//Recursive function that will only exit once it returns true
bool glossLevel(float& gl)
{
    bool isAssigned = 0;

    if (gl >= 0.1 && gl <= 5)
    {
        //obj = new Flat(color, gl, numPaint);
        isAssigned = 1;
    }
    else if (gl >= 10.5 && gl <= 25)
    {
        //obj = new Eggshell(color, gl, numPaint);
        isAssigned = 1;
    }
    else if (gl >= 25.5 && gl <= 35)
    {
        //obj = new Satin(color, gl, numPaint);
        isAssigned = 1;
    }
    else if (gl >= 35.5 && gl <= 70)
    {
        //obj = new SemiGloss(color, gl, numPaint);
        isAssigned = 1;
    }
    else if (gl >= 85 && gl <= 95)
    {
        //obj = new HighGloss(color, gl, numPaint);
        isAssigned = 1;
    }

    if (!isAssigned)
    {
        cout << "GlossLevel " << gl << " is not allowed.\nEnter glosslevel: ";
        cin >> gl;
        return glossLevel(gl);
    }

    return isAssigned;
}

//Passes all the data by reference and adds to the object in main
void inputData(string& color, float& numPaint)
{
    cout << "What color is the paint: ";
    cin >> color;

    while (!cin)
    {
        cin.clear();
        cin.ignore(123, '\n');

        cout << "Error...\n\n";
        cout << "What color is the paint: ";
        cin >> color;

    }

    validColors(color);

    //transform(color.begin(), color.end(), color.begin(), ::toupper);

    cout << "How many cans are in inventory: ";
    cin >> numPaint;

    while (!cin || numPaint < 0)
    {
        cin.clear();
        cin.ignore(123, '\n');

        cout << "Bad input...\n\n";

        cout << "How many cans are in inventory: ";
        cin >> numPaint;
    }
}
