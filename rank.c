
void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int i, j;
    float avg2 = 0.0;
    float pass_avg = 0.0;
    int passed = 0;

    //*num_passed = 0;
    //*avg = 0.0;
    //*passing_avg = 0.0;

    // init ranks
    /*for (i = 0; i < N; i++) {
        R[i] = 1;
    }*/

    // compute ranks
    for (i = 0; i < N; i+=2) {
        int rank1 = 1;
        int rank2 = 1;
        float grade1 = F[i];
        float grade2 = F[i+1];
        for (j = 0; j < N; j++) {
            if (grade1 < F[j]) {
                rank1++;
            }
            if (grade2 < F[j]) {
                rank2++;
            }
        }
        R[i] = rank1;
        R[i+1] = rank2;
    }
    // compute averages
    for (i = 0; i < N; i++) {
        float grade = F[i];
        avg2 += grade;
        if (grade >= 50.0) {
            pass_avg += grade;
            passed += 1;
        }
    }

    // check for div by 0
    if (N > 0) avg2 /= N;
    if (passed) pass_avg /= passed;
    *num_passed = passed;
    *passing_avg = pass_avg;
    *avg = avg2;
} // compute_ranks

