#include "dorm.h"

// menggunakan fungsi struct dorm
struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t dorm; // membuat struct dorm yang sementara
    memset(temp.name, '\0', sizeof(temp.name));   // karakter diinisialisasi = NULL
    strcpy(temp.name, _name);  // parameter ke  struct dorm sementara
    temp.capacity = _capacity;
    temp.resident_num = 0;  // mengatur jumlah penghuni asrama = 0
    temp.gender = _gender;  // menetapkan jenis kelamin dari parameter
    return temp;
}

// cetak detail dorm
void print_dorm(struct dorm_t *dorm, int temphsow)
{
    int j;
    // buat loopng setiap dorm
    for (j = 0; j < tempshow; j++)
    {
        printf("%s|%d|", dorm[j].name, dorm[j].capacity);
        if (dorm[j].gender == GENDER_MALE) // Jika jenis kelamin dorm adalah pria
        {
            printf("male\n"); 
        }
        else // Jika jenis kelamin dorm adalah wanita
        {
            printf("female\n"); 
        }
    }
}

// mencetak detail lengkap dorm
void print_dorm_detail(struct dorm_t *dorm, int tempshow)
{
    int j;
    for (j = 0; j < tempshow; j++) // Looping melalui setiap dorm
    {
        printf("%s|%d|", dorm[j].name, dorm[j].capacity); // Mencetak nama dan kapasitas dorm
        if (dorm[j].gender == GENDER_MALE) // Jika jenis kelamin dorm adalah pria
        {
            printf("male|"); // Mencetak "male"
        }
        else // Jika jenis kelamin dorm adalah wanita
        {
            printf("female|"); // Mencetak "female"
        }
        printf("%d\n", dorm[j].residents_num); // Mencetak jumlah penghuni dorm
    }
}