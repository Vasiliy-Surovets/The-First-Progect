#include <TXlib.h>

class Map
{
    public:
    Map();
    ~Map();
    void sprite(HDC a);

    void draw();
    int checkin(int g);
    int burst(int a);

    private:
    HDC text;
    int tip, k, whSrc;
    int block[18][18];
};

Map::Map()
{
    k = 50;
    whSrc = 9;
    int a[18][18]{
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 2, 1, 1, 2, 1, 5, 2, 5, 1, 2, 1, 1, 2, 1, 1, 2, 3},
    {3, 2, 5, 1, 2, 1, 1, 2, 1, 5, 2, 1, 5, 2, 1, 5, 2, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 2, 3, 3, 3, 2, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
    };
    for (int j = 0; j < 18; j++)
    {
        for (int i = 0; i < 18; i++)
        {
            block[i][j] = a[j][i];
        }
    }
}

Map::~Map()
{
    cout << "Map OK" << std::endl;
}

void Map::sprite(HDC a)
    {
        text = a;
    }


void Map::draw()
    {
        for (int j = 0; j < 18; j++)
            {
                for (int i = 0; i < 18; i++)
                    {
                        if (block[i][j] == 3)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 51, 1, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 2)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 41, 1, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 4)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 71, 1, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 5)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 51, 11, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 6)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 61, 11, whSrc, whSrc, TX_BLACK);
                            }
                        else
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 61, 1, whSrc, whSrc, TX_BLACK);
                            }
                    }
            }
    }

int Map::checkin(int g)
    {
        int i, j, c;
        i = g / 100;
        j = g - (g / 100) * 100;
        c = block[i][j];
        return c;
    }

int Map::burst(int a)
    {
        int i, j, c;
        i = a / 100;
        j = a - (a / 100) * 100;

        c = block[i][j];



        if (c == 2)
        {
            block[i][j] = 4;
        }
        if (c == 5)
        {
            block[i][j] = 6;
        }
        return c;

    }

