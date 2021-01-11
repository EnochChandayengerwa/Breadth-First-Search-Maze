for (int h = 0; h < m; h++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (maze[h][k] == " ")
                    {
                        cout << distance[h][k] << "  ";
                    }
                    else
                    {
                        cout << maze[h][k] << "  ";
                    }
                }
                cout << endl;
            }
            cout << endl;