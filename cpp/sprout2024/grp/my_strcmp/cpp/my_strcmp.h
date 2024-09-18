int my_strcmp(char *a, char *b) {
    int i = 0;
    while (*(a + i) != '\0' && *(b + i) != '\0') {
        if (*(a + i) != *(b + i)) {
            return 1;
        }
        i += sizeof(char);
    }
    return 0;
}
