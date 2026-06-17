#include <iostream>
#include <string>
void CastSpell(std::string spellName, std::string effect, int damage)
{
    std::cout << "You cast " << spellName << ".\n";
    std::cout << effect << "\n";
    std::cout << "The enemy takes " << damage << " damage. \n";
}

int main()
{
    int spellChoice;
    std::string input;
    std::cout << "Choose a spell:\n";
    std::cout << "1. Fire\n";
    std::cout << "2. Ice\n";
    std::cout << "3. Shadow\n";
    std::cout << "Enter choice: ";
    try { // added input validation
        std::getline(std::cin, input);
        spellChoice = stoi(input);
    }
    catch (...)
    {
        std::cout << "\nThat spell wasn't listed.\n";
    }

    if (spellChoice == 1)
    {
        CastSpell("Fire", "The room gets warmer", 10);
    }
    else if (spellChoice == 2)
    {
        CastSpell("Ice", "The room gets colder", 8);
    }
    else if (spellChoice == 3)
    {
        CastSpell("Shadow", "The lights flicker", 12);
    }
    else
    {
        std::cout << "Invalid spell.\n";
    }
    std::cin.get();
    return 0;
}