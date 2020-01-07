//Frank Tancredi
#include <iostream>
#include <fstream>
#include <time.h>
#include <fstream>

using namespace std;

class DDGenerator
{
    private:
        char playerGender;
        string playerType, playerRace, playerFirstName, playerLastName; //Type =  D&D "Class" definition. Renamed type to differentiate between C++ class definiton.
        int strength, intelligence, wisdom, dexterity, constitution, charisma;
        
        int racePick, typePick;
    public:
        DDGenerator();
        int abilityScores[5];
        
        //Program Generated
        void generateGender();
        void generateRace();
        void generateName();
        void generateType();
        void generateAbilityScores();                   
        void assignAbilityScores();                            
        
        //User Created
        void pickGender();                               
        void pickRace();
        void pickName();
        void pickType();
        
        //End Calculation
        void generateTotalStats();
        void saveCharacter();

};

DDGenerator::DDGenerator() //Class Constructor
{
    int abilityscores[5] = {0,0,0,0,0};
    int strength = 0, intelligence = 0, wisdom = 0, dexterity = 0, constitution = 0, charisma = 0;
    int racePick = 0, typePick = 0;
}

void DDGenerator::generateGender() //RNG assigns a gender to the character based off of generated number
{
    int genderPick;
    srand(time(0));
    genderPick = (rand() % 1) + 1;
    switch (genderPick)
    {
        case 1:
            playerGender = 'M';
        case 2:
            playerGender = 'F';       
    }
}

void DDGenerator::generateRace() //RNG assigns a race to the character based off of generated number
{
    srand(time(0));
    racePick = (rand() % 6) + 1;
    switch (racePick)
    {
        case 1:
            playerRace = "Halfling";
            break;
        case 2:
            playerRace = "Human";
            break;
        case 3:
            playerRace = "Half-Orc";
            break;
        case 4:
            playerRace = "Gnome";
            break;
        case 5:
            playerRace = "Elf";
            break;
        case 6: 
            playerRace = "Dwarf";  
            break;              
    }    
}

void DDGenerator::generateName() //Randomly chooses pre-made names corresponding to gender and race using fileio and RNG
{
    int random, count = 1;
    string line;
    switch(racePick)
    {     
        case 1: //Halfling
        {
            if (playerGender == 'm' || playerGender == 'M') //Narrows selection to male names if gender is male
            {
                ifstream halflingNameM ("humanmalenames.txt"); //Humans and Halflings share first and last name pool
                if(halflingNameM.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(halflingNameM,line)) 
                    {   
                        if (count == random) // assigns character the name found on line "random" of the human/halfling first name text file
                        {
                            playerFirstName = line;
                        }
                        count++; //allows program to read through text file until line "random" is found"                        
                    } 
                }
                halflingNameM.close();
            }
            else if (playerGender == 'f' || playerGender == 'F') //Narrows selection to female names, etc...
            {
                ifstream halflingNameF ("humanfemalenames.txt");
                if(halflingNameF.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(halflingNameF,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        } 
                        count++;   
                    } 
                }
                halflingNameF.close(); 
            }   
            count = 0;
            ifstream halflingNameL ("humanlastnames.txt"); //All races besides half-orc have gender unrestricted last name pools 
            if(halflingNameL.is_open())  
            {     
                random = (rand() % 14) + 1; 
                while(getline(halflingNameL,line)) 
                {   
                    if (count == random)
                    {      
                        playerLastName = line;
                    }
                    count++;    
                } 
            }
            halflingNameL.close();          
        }
        break;
        
        case 2: //Human
        {
            if (playerGender == 'm' || playerGender == 'M')
            {
                ifstream humanNameM ("humanmalenames.txt"); 
                if(humanNameM.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(humanNameM,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                }
                humanNameM.close();  
            }
            else if (playerGender == 'f' || playerGender == 'F')
            {
                ifstream humanNameF ("humanfemalenames.txt"); 
                if(humanNameF.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(humanNameF,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                } 
                humanNameF.close();
            }
            count = 0;
            ifstream humanNameL ("humanlastnames.txt"); 
            if(humanNameL.is_open()) 
            {     
                random = (rand() % 14) + 1; 
                while(getline(humanNameL,line)) 
                {   
                    if (count == random)
                    {
                        playerLastName = line;
                    }
                    count++;
                            
                } 
            }
            humanNameL.close(); 
        } 
        break;
        
        case 3:  //Half-Orc (Half-Orcs do not usually have last names)
        {
            if (playerGender == 'm' || playerGender == 'M')
            {
                ifstream orcNameM ("orcmalenames.txt"); 
                if(orcNameM.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(orcNameM,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                }
                orcNameM.close();  
            }
            else if (playerGender == 'f' || playerGender == 'F')
            {
                ifstream orcNameF ("orcfemalenames.txt"); 
                if(orcNameF.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(orcNameF,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                }
                orcNameF.close();  
            }   
        }
        break;
        
        case 4:  //Gnome
        {
            if (playerGender == 'm' || playerGender == 'M')
            {
                ifstream gnomeNameM ("gnomemalenames.txt"); 
                if(gnomeNameM.is_open())  
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(gnomeNameM,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                }
                gnomeNameM.close();  
            }
            else if (playerGender == 'f' || playerGender == 'F')
            {
                ifstream gnomeNameF ("gnomefemalenames.txt"); 
                if(gnomeNameF.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(gnomeNameF,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                } 
                gnomeNameF.close(); 
            }
            count = 0;
            ifstream gnomeNameL ("gnomelastnames.txt");
            if(gnomeNameL.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(gnomeNameL,line)) 
                    {   
                        if (count == random)
                        {
                            playerLastName = line;
                        }
                        count++;
                            
                    } 
                }
            gnomeNameL.close();  
        }
        break;
        
        case 5:  //Elf
        {
            if (playerGender == 'm' || playerGender == 'M')
            {
                ifstream elfNameM ("elfmalenames.txt"); 
                if(elfNameM.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(elfNameM,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                }
                elfNameM.close();  
            }
            else if (playerGender == 'f' || playerGender == 'F')
            {
                ifstream elfNameF ("elffemalenames.txt"); 
                if(elfNameF.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(elfNameF,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                } 
                elfNameF.close(); 
            }
            count = 0;
            ifstream elfNameL ("elflastnames.txt");
            if(elfNameL.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(elfNameL,line)) 
                    {   
                        if (count == random)
                        {
                            playerLastName = line;
                        }
                        count++;
                            
                    } 
                }
            elfNameL.close(); 
        } 
        break;
        
        case 6:  //Dwarf
        {
            if (playerGender == 'm' || playerGender == 'M')
            {
                ifstream dwarfNameM ("dwarfmalenames.txt"); 
                if(dwarfNameM.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(dwarfNameM,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                }
                dwarfNameM.close();  
            }
            else if (playerGender == 'f' || playerGender == 'F')
            {
                ifstream dwarfNameF ("dwarffemalenames.txt"); 
                if(dwarfNameF.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(dwarfNameF,line)) 
                    {   
                        if (count == random)
                        {
                            playerFirstName = line;
                        }
                        count++;
                            
                    } 
                } 
                dwarfNameF.close(); 
            }
            count = 0;
            ifstream dwarfNameL ("dwarflastnames.txt");
            if(dwarfNameL.is_open()) 
                {     
                    random = (rand() % 14) + 1; 
                    while(getline(dwarfNameL,line)) 
                    {   
                        if (count == random)
                        {
                            playerLastName = line;
                        }
                        count++;
                            
                    } 
                }
            dwarfNameL.close();  
        } 
        break; 
    } 
}

void DDGenerator::generateType() //RNG assigns a type to the character
{
    srand(time(0));
    typePick = (rand() % 3) + 1;
    switch (typePick)
    {
        case 1:
             playerType = "Fighter";
             break;
        case 2:
             playerType = "Rogue";
             break;
        case 3:
             playerType = "Wizard";
             break;
        case 4:
             playerType = "Cleric";
             break;     
           
    }
}

void DDGenerator::generateAbilityScores() /*Follows standard rulebook for generating ability scores, using RNG to "roll" 
a six sided die four times for each ability. The lowest of the four rolls is discarded and the highest 3 are added together to form
one of the six scores */
{
    int tempScoreHolder[4], temp, random;
    srand(time(0));
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            random = (rand() % 6) + 1;
            tempScoreHolder[y] = random;
        }
        for (int y = 0; y < 3; y++) //Sorts the four roll outcomes to easily allow the lowest outcome to be discarded
        {
            for (int z = 5; z >= y; z--)
            if (tempScoreHolder[z] > tempScoreHolder[z+1])
            {
                temp = tempScoreHolder[z+1];
                tempScoreHolder[z+1] = tempScoreHolder[z];
                tempScoreHolder[z] = temp;
            }
        }
        abilityScores[x] = tempScoreHolder[1] + tempScoreHolder[2] + tempScoreHolder[3];  //adds the highest three outcomes together to form one score
    }
}

void DDGenerator::assignAbilityScores() /*Sorts the final ability scores and distributes them to various abilities depending on character
types' priorety of them. Highest scores go to highest priorety abilties for a type, lowest go to lowest priorety*/
{
    int temp;
    for (int x = 0; x < 5; x++) //Sorting
    {
        for (int y = 5; y>= x; y--)
        {
            if (abilityScores[y] > abilityScores[y+1])
            {
                temp = abilityScores[y+1];
                abilityScores[y+1] = abilityScores[y];
                abilityScores[y] = temp;
            }
        }
    }
    switch (typePick)
    {
        case 1: //Fighter (Highest Priorety: Str, Const, dex)
             strength = abilityScores[5];
             constitution = abilityScores[4];
             dexterity = abilityScores[3];
             charisma = abilityScores[2];
             intelligence = abilityScores[1];
             wisdom = abilityScores[0];
             break;
        case 2: //Rogue (Highest Priorety: Dex, Const, Wis)
             dexterity = abilityScores[5];
             constitution = abilityScores[4];
             wisdom = abilityScores[3];
             strength = abilityScores[2];
             charisma = abilityScores[1];
             intelligence = abilityScores[0];
             break;
        case 3: //Wizard (Highest Priorety: Intel, Dex, Const)
             intelligence = abilityScores[5];
             dexterity = abilityScores[4];
             constitution = abilityScores[3];
             wisdom = abilityScores[2];
             charisma = abilityScores[1];
             strength = abilityScores[0];
             break;
        case 4: //Cleric (Highest Priorety: Wis, Char, Str)
             wisdom = abilityScores[5];
             charisma = abilityScores [4];
             strength = abilityScores [3];
             dexterity = abilityScores [2];
             constitution = abilityScores [1];
             intelligence = abilityScores [0]; 
             break;              
    }
}

void DDGenerator::generateTotalStats() //For user and program generated characters, compiles all the character data and displays it for the user
{
    cout << "------------------------------\n";
    cout << "Character Name: " << playerFirstName << " " << playerLastName << "(" << playerGender << ")\n";
    cout << "Character Race: " << playerRace << "\n";
    cout << "Character Class: " << playerType << "\n\n";
    cout << "Character Stats \n" <<
    "Strength: " << strength << "\n"
    "Dexterity: " << dexterity << "\n"
    "Constitution: "  << constitution << "\n"
    "Intelligence: "  << intelligence << "\n"
    "Wisdom: "  << wisdom << "\n"
    "Charisma: "  << charisma << "\n\n";
    cout << "------------------------------\n\n";
    cout << "You're now ready to play! Bring these stats to your DM and begin your adventure!\n\n";
    
}
 
void DDGenerator::pickGender() //Allows user to input desired character gender
{
    cout <<"What is your desired gender for your character? (M/F) \n";
    cin >> playerGender;
}

void DDGenerator::pickRace() //Allows user to input desired character race with the option of learning more about any of them
{
    int raceSelect, count = 0;
    string line;
    bool repeat = true; 
    while(repeat == true) //Allows menu to be re-printed if user opts to see a description instead of choosing immediately
    { 
        cout << "Select a race, or a race description to learn more: \n"
        << "1.) Halfling \n"
        << "2.) Human \n"
        << "3.) Half-Orc \n"
        << "4.) Gnome \n"
        << "5.) Elf \n"
        << "6.) Dwarf \n"
        << "7.) Halfling Description \n"
        << "8.) Human Description \n"
        << "5.) Half-Orc Description \n"
        << "6.) Gnome Description \n"
        << "7.) Elf Description \n"
        << "8.) Dwarf Description \n";
        cin >> raceSelect;
        cout << "\n";
        if (raceSelect == 1)
        {
            playerRace = "Halfling";
            repeat = false;
        }
        else if (raceSelect == 2)
        {
            playerRace = "Human";
            repeat = false;
        } 
        else if (raceSelect == 3)
        {
            playerRace = "Half-Orc";
            repeat = false;
        }
        else if (raceSelect == 4)
        {
            playerRace = "Gnome";
            repeat = false;
        } 
         else if (raceSelect == 5)
        {
            playerRace = "Elf";
            repeat = false;
        }
        else if (raceSelect == 6)
        {
            playerRace = "Dwarf";
            repeat = false;
        } 
        else if (raceSelect == 7 || raceSelect == 8 || raceSelect == 9 || raceSelect == 10
        || raceSelect == 11 || raceSelect == 12) /*Certain sections of "raceinfo.txt" are assigned to the descriptions of certain races.
        selecting a certain race's description option will display only that race's section*/
        {
            ifstream racedesc ("raceinfo.txt"); //Opens the race information text file for reading
                if(racedesc.is_open()) 
                {     
                    while(getline(racedesc,line)) 
                    {
                        if (raceSelect == 7)
                        {   
                            if (count >= 1 && count <= 15) //Halfling Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (raceSelect == 8)
                        {   
                            if (count > 16 && count <= 33) //Human Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (raceSelect == 9)
                        {   
                            if (count > 34 && count <= 50) //Half-Orc Description 
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (raceSelect == 10)
                        {   
                            if (count > 51 && count <= 68) //Gnome Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (raceSelect == 11)
                        {   
                            if (count > 69 && count <= 90) //Elf Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (raceSelect == 12)
                        {   
                            if (count > 91 && count <= 112) //Dwarf Description
                            {
                                cout << line << "\n";
                            }
                        }
                        count++;
                            
                    } 
                }
                racedesc.close(); 
                cout << "\n";   
        }
    count = 0;
    }
}

void DDGenerator::pickName() //Allows user to input desired character name
{
    cout << "What will your character's first name be? \n";
    cin >> playerFirstName;
    cout << "What will your character's last name be? \n";
    cin >> playerLastName;
    cout << "\n";    
} 
void DDGenerator::pickType() //Allows user to input desired character type with the option of learning more about any of them
{
    int typeSelect, count = 0;
    string line;
    bool repeat = true; 
    while(repeat == true)
    { 
        cout << "Select a class, or a class description to learn more: \n"
        << "1.) Fighter \n"
        << "2.) Rogue \n"
        << "3.) Wizard \n"
        << "4.) Cleric \n"
        << "5.) Fighter Description \n"
        << "6.) Rogue Description \n"
        << "7.) Wizard Description \n"
        << "8.) Cleric Description \n";
        cin >> typeSelect;
        cout << "\n";
        if (typeSelect == 1)
        {
            playerType = "Fighter";
            typePick = 1;
            repeat = false;
        }
        else if (typeSelect == 2)
        {
            playerType = "Rogue";
            typePick = 2;
            repeat = false;
        } 
        else if (typeSelect == 3)
        {
            playerType = "Wizard";
            typePick = 3;
            repeat = false;
        }
        else if (typeSelect == 4)
        {
            playerType = "Cleric";
            typePick = 4;
            repeat = false;
        } 
        else if (typeSelect == 5 || typeSelect == 6 || typeSelect == 7 || typeSelect == 8)
        {
            ifstream typedesc ("typeinfo.txt"); 
                if(typedesc.is_open()) 
                {     
                    while(getline(typedesc,line)) 
                    {
                        if (typeSelect == 5)
                        {   
                            if (count >= 1 && count <= 16) //Fighter Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (typeSelect == 6)
                        {   
                            if (count > 17 && count <= 36) //Rogue Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (typeSelect == 7)
                        {   
                            if (count > 37 && count <= 55) //Wizard Description
                            {
                                cout << line << "\n";
                            }
                        }
                        else if (typeSelect == 8)
                        {   
                            if (count > 56 && count <= 75) //Cleric Description
                            {
                                cout << line << "\n";
                            }
                        }
                        count++;
                            
                    } 
                }
                typedesc.close();    
    }
    count = 0;
    }
}

void DDGenerator::saveCharacter() //Saves all statistic to "createdcharacters.txt" as it was displayed in the console
{
    char save;
    cout << "Would you like to save this character to the createdcharacters text file? (Y/N)\n";
    cin >> save;  
    cout << "\n";
    if (save == 'y' || save == 'Y')
    {
        ofstream saveFile("createdcharacters.txt",ios::app);
        saveFile <<  "------------------------------\n"
        << "Character Name: " << playerFirstName << " "
        << playerLastName << "(" << playerGender << ")\n"
        << "Character Race: " << playerRace << "\n"
        << "Character Class: " << playerType << "\n\n"
        << "Character Stats \n" <<
        "Strength: " << strength << "\n"
        "Dexterity: " << dexterity << "\n"
        "Constitution: "  << constitution << "\n"
        "Intelligence: "  << intelligence << "\n"
        "Wisdom: "  << wisdom << "\n"
        "Charisma: "  << charisma << "\n\n"
        << "------------------------------\n\n";
        saveFile.close();
        cout << "Character saved! If you ever want to see their stats again, just open up \n" 
        << "createdcharacters.txt in the DDHonors folder. \n" 
        << "Thanks for using DDGenerator. Have fun!\n";
    }
    else if (save == 'n' || save == 'N')
    {
        cout << "Thanks for using DDGenerator. Have fun!\n";
    }
}

int main()
{
    int test, choice;
    DDGenerator MyGenerator;

    cout << "Welcome to DDGenerator, the Pathfinder Character Creator for Novice players. \n";
    cout << "What would you like to do? \n";
    cout << "1.) Create your own character \n";
    cout << "2.) Have the program create a character for you \n";
    cin >> choice;
    cout <<"\n";
    if (choice == 1) //Player created
    {
        MyGenerator.pickGender();
        MyGenerator.pickRace();
        MyGenerator.pickName();
        MyGenerator.pickType();
        MyGenerator.generateAbilityScores();
        MyGenerator.assignAbilityScores();
        MyGenerator.generateTotalStats();
        MyGenerator.saveCharacter();          
    }
    else if (choice == 2) //Program created
    {
        MyGenerator.generateGender();
        MyGenerator.generateRace();
        MyGenerator.generateName();
        MyGenerator.generateType();
        MyGenerator.generateAbilityScores();
        MyGenerator.assignAbilityScores();
        MyGenerator.generateTotalStats();
        MyGenerator.saveCharacter();
    }   
    system("PAUSE");   
}
