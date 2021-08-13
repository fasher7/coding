        temp = numArr[num - 1];
        temp3 = numArr[0];
        for (int y = 1; y < num; ++y)
        {
            if (y + 1 != num)
            {
                temp2 = numArr[y];
                numArr[y] = temp3;
                temp3 = temp2;
            }
            else
            {
                numArr[y] = temp2;
            }
        }
        numArr[0] = temp;
        --RC;

// this can be used to change 1 2 3 4 -> 4 1 2 3 -> 3 4 1 2 and so on
