#include "Helper.h"

using namespace std;

vector<int> Helper::stringToVector(const int size, const string& str)
{
    vector<int> data(size);
    unsigned int i, j = 0;

    // O� \0 suppos�ment la fin de ligne.
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
        {
            continue;
        }

        // Modifie la valeur de cette entr�e en fonction de la somme du caract�re ASCII de la cha�ne.
        data[j] = data[j] * 10 + (str[i] - 48);

        // On passe � la tuile suivante (fin du nombre pr�c�dent).
        if (str[i + 1] == ',') j++;
    }

    return data;
}