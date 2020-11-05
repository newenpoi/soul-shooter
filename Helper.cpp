#include "Helper.h"

using namespace std;

vector<int> Helper::stringToVector(const int size, const string& str)
{
    vector<int> data(size);
    unsigned int i, j = 0;

    // Où \0 supposément la fin de ligne.
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
        {
            continue;
        }

        // Modifie la valeur de cette entrée en fonction de la somme du caractère ASCII de la chaîne.
        data[j] = data[j] * 10 + (str[i] - 48);

        // On passe à la tuile suivante (fin du nombre précédent).
        if (str[i + 1] == ',') j++;
    }

    return data;
}