#include <stdio.h>
#include <string.h>

int hitungDiskon(int tempHarga, float x) {
    return tempHarga * x;
}

char tampilkanStruk (int diskon, int tempHarga, char spasi) {
    int hargaDiskon = tempHarga - diskon;
    printf("=============================================\n");
    printf("|Total Harga %-17c : Rp. %-7d |\n", spasi, tempHarga);
    printf("|Anda Menghemat %-14c : Rp. %-7d |\n", spasi, diskon);
    printf("|Total Bayar %-17c : Rp. %-7d |\n", spasi, hargaDiskon);
    printf("=============================================\n");
    printf("| ----- TERIMA KASIH SUDAH BERBELANJA ----- |\n");
    printf("=============================================\n");
    printf("\n");
}

int main() {
    char *barang[] = {"Pensil", "Pulpen", "Penghapus", "Penggaris", "Tipe-x", "Rautan Pensil", "Spidol", "Buku Tulis", "Stabilo"};
    int hargaSatuan[] = {3000, 5000, 2000, 10000, 6000, 2500, 7000, 8000, 6500};
    int nomor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int diskon;

    printf("=========================================\n");
    printf("|   List Semua Barang    | Harga Satuan |\n");
    printf("=========================================\n");
    for (int i = 0; i < 9; i++) {
        printf("|%d. %-20s | Rp. %-8d | \n", nomor[i], barang[i], hargaSatuan[i]);
    }
    printf("=========================================\n");
    printf("\n");

    int nomorBarang[20];
    int jumlahBarang[20];
    char pilihan;
    for (int i = 0; i < 20; i++) {
        printf("Masukkan kode barang ke-%d: ", i+1);
        scanf("%d", &nomorBarang[i]);
        printf("Masukkan jumlah barang: ");
        scanf("%d", &jumlahBarang[i]);
        printf("Apakah lanjut? (Y/N): ");
        scanf(" %c", &pilihan);
        if (pilihan == 'n' || pilihan == 'N') {
            printf("\n=============================================\n");
            printf("|              Toko Alat Tulis              |\n");
            printf("|                - PAK ANDI -               |\n");
            printf("=============================================\n");
            printf("|              STRUK PEMBELIAN              |\n");
            printf("=============================================\n");
            printf("| Barang yang dibeli | Jumlah | Total Harga |\n");
            printf("=============================================\n");
            int tempHarga = 0;
            for (int j = 0; j <= i; j++) {
                int index = nomorBarang[j] - 1;
                int totalHarga = hargaSatuan[index] * jumlahBarang[j];
                printf("|%-19s | %-6d | Rp. %-7d |\n", barang[index], jumlahBarang[j], totalHarga);
                tempHarga = tempHarga + totalHarga;
            }
            
            char spasi;
            if (tempHarga >= 200000) {
                diskon = hitungDiskon(tempHarga, 0.15);
                tampilkanStruk (diskon, tempHarga, spasi);
                break;
            }
                else if (tempHarga >= 100000) {
                    diskon = hitungDiskon(tempHarga, 0.10);
                    tampilkanStruk (diskon, tempHarga, spasi);
                    break;
            }
                else {
                    diskon = 0;
                    tampilkanStruk (diskon, tempHarga, spasi);
                    break;
            }
        }
    }
    return 0;
}