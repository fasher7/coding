    while (RC != 0)
    {
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
    }

OR

    int change;
    int tempArr[num];

    for (int j = 0; j < num; ++j)
    {
        tempArr[j] = numArr[j];
    }

    for (int y = 0; y < num; ++y)
    {
        change = (y + RC) % num;
        numArr[change] = tempArr[y];
    }

OR

static int[] circularArrayRotation(int[] a, int k, int[] queries) 
{

            int arr[] = new int[a.length];
						
            for(int i=0 ; i<a.length ; i++)
                arr[(i+k)%a.length] = a[i];
								
            for(int i=0 ; i<queries.length ; i++)
                queries[i] = arr[queries[i]];
								
            return queries;    
}

// here RC = k = number of rotations
// this can be used to change 1 2 3 4 -> 4 1 2 3 -> 3 4 1 2 and so on
