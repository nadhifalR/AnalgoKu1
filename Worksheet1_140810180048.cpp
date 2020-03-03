/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N  5

bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
           return false;
    }
}

void stableMarriage(int prefer[2*N][N], string name[10])
{
    int wPartner[N];

    bool mFree[N];

    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;

        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];

            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else
            {
                int m1 = wPartner[w-N];

                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

    cout << "Man   Woman" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << name[i+N] << "\t" << name[wPartner[i]] << endl;
}

int main()
{
    string name[10] = {"Amy","Bertha","Clare","Diane","Erika", "Victor","Wyatt","Xavier","Yancey","Zeus"};

    int prefer[2*N][N] = {
        {6, 5, 8, 9, 7},
        {8, 6, 5, 7, 9},
        {6, 9, 7, 8, 5},
        {5, 8, 7, 6, 9},
        {6, 8, 5, 9, 7},

        {4, 0, 1, 3, 2},
        {2, 1, 3, 0, 4},
        {1, 2, 3, 4, 0},
        {0, 4, 3, 2, 1},
        {3, 1, 4, 2, 0},

    };
    stableMarriage(prefer, name);

    return 0;
}
