#include <pinyin.h>
#include <stdio.h>

int main()
{
    char input[64];
    pinyin_context_t * context = pinyin_init (SYSTEM_CONF, "");

    if (context == NULL)
    {
        printf("Context not allocted...\n");
        return 1;
    }

    pinyin_instance_t * instance = pinyin_alloc_instance (context);

    if (instance == NULL)
    {
        printf("Instance not allocted...\n");
        return 1;
    }

    printf("Please input pinyin:\n");

    scanf("%s", input);

    pinyin_parse_more_full_pinyins (instance, input);

    pinyin_guess_sentence (instance);

    guint number;

    pinyin_guess_candidates(instance, 0, {});

    pinyin_get_n_candidate (instance, &number);

    printf ("%s has %d candidates\n", input, number);

    for (guint i = 0; i < 5 && i < number; ++i)
    {
        lookup_candidate_t * candidate;
        pinyin_get_candidate(instance, i, &candidate);

        const gchar *display_string;
        pinyin_get_candidate_string(instance, candidate, &display_string);
        printf("%s\t", display_string);
    }
    printf("\n");

    pinyin_free_instance (instance);

    pinyin_fini (context);

    return 0;
}

