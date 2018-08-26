#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

///A DFS based recursive function that returns true if a
///matching for vertex(peak) @u is possible
bool bpm(bool** bpGraph, int u, bool seen[], int matchR[], int numberOfJobs) {
    for (int i = 0; i < numberOfJobs; ++i) {
        ///If applicant @u is interested int job
        ///@i and @i isn't visited
        if (bpGraph[u][i] && !seen[i]) {
            seen[i] = true; ///mark @i as visited

            ///If job @i is not assigned to an applicant OR
            ///previously assigned applicant for job @i
            ///(which is @marchR[i]) has an alternate job available.
            ///Since @i is marked as visited in the above line, @matchR[i]
            ///in the following recursive call will not get job @i again.
            if (matchR[i] < 0 || bpm(bpGraph, matchR[i], seen, matchR, numberOfJobs)) {
                matchR[i] = u;
                return true;
            }
        }
    }
    return false;
}

///Returns maximum number of matching from between @numberOfApplicant and @numberOfJob
int maxBPM(bool** bpGraph, int numberOfJobs, int numberOfApplicant) {
    ///An array to keep track of the applicants assigned to jobs.
    ///The value of @matchR[i] is the applicant number assigned
    ///to job @i, the value -1 indicates nobody is assigned.

    int matchR[numberOfJobs];
    for (int i = 0; i < numberOfJobs; ++i) {
        matchR[i] = -1;
    }

    int result = 0; ///Count of jobs assigned to applicants
    for (int i = 0; i < numberOfApplicant; ++i) {
        bool seen[numberOfJobs];
        for (int j = 0; j < numberOfJobs; ++j) {
            seen[j] = false;
        }

        ///Find if the applicant @i can gat a job
        if (bpm(bpGraph, i, seen, matchR, numberOfApplicant)) {
            result++;
        }
    }

    return result;
}

int main() {
    FILE* in;
    if( !(in = fopen("in.txt", "r"))) {
        printf("The file doesn't exist.");
        return 1;
    }
    int numberOfJobs, numberOfApplicants, numberOfEdges;
    fscanf(in, "%d%d%d", &numberOfJobs, &numberOfApplicants, &numberOfEdges);
    bool** bpGraph = (bool**)calloc(numberOfJobs, sizeof(bool*));
    for (int i = 0; i < numberOfJobs; ++i) {
        bpGraph[i] = (bool*)calloc(numberOfJobs, sizeof(bool));
    }

    int node1, node2;
    for (int i = 0; i < numberOfEdges; ++i) {
        fscanf(in, "%d%d", &node1, &node2);
        bpGraph[node1][node2] = 1;
    }

    printf("Maximum number of applicants that can get job is: %d", maxBPM(bpGraph, numberOfJobs, numberOfApplicants));

    fclose(in);
//    for (int i = 0; i < numberOfJobs; ++i) {
//        free(bpGraph[i]);
//    }
//    free(bpGraph);
    return 0;
}