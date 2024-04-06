for (int i = m; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    v[m][j] = v[i-m][j];
                }
            }