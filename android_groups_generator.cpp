#include <stdio.h>
#include <string.h>
#include <memory.h>

#include <private/android_filesystem_config.h>


int main() {
    int i = 0;
    const int NUM_GROUPS = sizeof(android_ids) / sizeof(android_ids[0]);

    FILE *f = fopen("android_groups.json", "wt");
    if (f) {
        fprintf(f, "{\n");
        for (i = 0; i < NUM_GROUPS; i++ ) {
            fprintf(f, "\t");
            fprintf(f, "\"%u\": \"%s\"", android_ids[i].aid, android_ids[i].name);
            if (i < NUM_GROUPS - 1) {
                fprintf(f, ",");
            }
            fprintf(f, "\n");
        }
        fprintf(f, "}\n");
        fclose(f);
    }

    f = fopen("add_android_groups.sh", "wt");
    if (f) {
        fprintf(f, "#/bin/sh\n");
        for (i = 0; i < NUM_GROUPS; i++ ) {
            /* skip adding root */
            if (android_ids[i].aid == 0) continue;
            fprintf(f, "echo \"%d/%d adding aid_%s (%u)\"\n", i+1, NUM_GROUPS, android_ids[i].name, android_ids[i].aid);
            fprintf(f, "sudo groupadd --gid %u aid_%s\n", android_ids[i].aid, android_ids[i].name);
            fprintf(f, "sudo useradd --gid %u --no-create-home --no-user-group --system --uid %u aid_%s\n",
                    android_ids[i].aid, android_ids[i].aid, android_ids[i].name);
        }
        fprintf(f, "\n");
        fclose(f);
    }
}
