// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <conio.h>
#include <iostream>

// Create a node
char kode[12], nama[50];
int usia;

struct Node {
	char kode_pasien[12], nama_pasien[50];
    int usia_pasien, data;
    
    struct Node* next;
};


char menu(){
	char pilihan;
	
	printf("----------PROGRAM DATA PASIEN----------\n");
	printf("1.	Input Data Pasien Baru\n");
	printf("2.	Cari Data Pasien Berdasarkan nama\n");
	printf("3.	Hapus Data  Pasien Berdasarkan Kode Pasien\n");
	printf("4.	Tampilkan Data Pasien Berdasarkan Usia Termuda\n");
	printf("5.	Tampilkan Data Pasien Berdasarkan Usia Tertua\n");
	printf("6.	Tampilkan Rata-rata Usia Pasien\n");
	printf("7.	Tampilkan Seluruh Data Pasien Beserta Jumlah Data Yang Tersimpan Dalam List\n");
	printf("8.	Keluar\n\n");
	printf("Pilihan: ");
	scanf(" %c", &pilihan);
	return pilihan;
}



// Insert the the end
void insertAtEnd(struct Node** head_ref, char *kode, char *nama, int usia) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; /* used in step 5*/

    strcpy(new_node->kode_pasien, kode);
    strcpy(new_node->nama_pasien, nama);
    new_node->usia_pasien = usia;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;

    last->next = new_node;
    return;
}

// Delete a node
void deleteNode(struct Node** head_ref, char *kode) {
    struct Node *temp = *head_ref, *prev;
	if(temp == NULL){
		printf("Data Masih Kosong!");
	} else {
		
		if (temp != NULL && strcmp(temp->kode_pasien, kode) == 0) {
        	*head_ref = temp->next;
        	free(temp);
        	printf("Data Dengan Kode %s Telah Dihapus!", kode);
        	return;
    	}
    	// Find the key to be deleted
    	while (temp != NULL && strcmp(temp->kode_pasien, kode) != 0) {
        	prev = temp;
        	temp = temp->next;
    	}

    	// If the key is not present
    	if (temp == NULL) {
    		printf("Data Tidak Ditemukan!!");
    		return;
		}

    	// Remove the node
    	prev->next = temp->next;

    	free(temp);
    	printf("Data Dengan Kode %s Telah Dihapus!", kode);
	}
}

// Search a node
int searchNode(struct Node** head_ref, char *nama) {
    struct Node* current = *head_ref;
	int i=0;
	int status = 0;
	if(current == NULL){
		printf("Data Pasien Masih Kosong!\n");
	} else {
		while (current != NULL) {
    		i++;
    		if (strcmp(current->nama_pasien, nama) == 0){
    			status++;
    			printf("------------------------------------------\n");
    			printf("Data Ke-%d \n", i);
    			printf("Kode Pasien : %s\n", current->kode_pasien);
				printf("Nama Pasien : %s\n", current->nama_pasien);
				printf("Usia Pasien : %d\n", current->usia_pasien);
				printf("------------------------------------------\n");
				break;
			} else{
        		current = current->next;
    		}
		}
		if(status == 0){
			printf("Pasien Dengan Nama %s Tidak Ditemukan!", nama);
		}
	}
}

//Less Usia
int usiaTermuda(struct Node** head_ref){
	struct Node* current = *head_ref;
	int tempUsia = 500;
	if(current == NULL){
		return 999;
	} else {
		while (current != NULL) {
    		if (current->usia_pasien < tempUsia){
				tempUsia = current->usia_pasien;
			} 
        	current = current->next;
		}
		
	}
	return tempUsia;
}

//More Usia
int usiaTertua(struct Node** head_ref){
struct Node* current = *head_ref;
	int tempUsia = 0;
	if(current == NULL){
		return 999;
	} else {
		while (current != NULL) {
    		if (current->usia_pasien > tempUsia){
				tempUsia = current->usia_pasien;
			} 
        	current = current->next;
		}
		
	}
	return tempUsia;
}

//FindSks
void findUsia(struct Node** head_ref, int usiaCom, char *statusCom){
	struct Node* current = *head_ref;
	int i=0;
	int status = 0;
	if(usiaCom == 999){
		printf("Data Pasien Masih Kosong!\n");
	} else {
		while (current != NULL) {
    		i++;
    		if (current->usia_pasien == usiaCom){
    			status++;
    			printf("---------- Usia Pasien %s ----------\n", statusCom);
    			printf("Data Ke-%d \n", i);
    			printf("Kode Pasien : %s\n", current->kode_pasien);
				printf("Nama Pasien : %s\n", current->nama_pasien);
				printf("Usia Pasien : %d\n", current->usia_pasien);
				printf("------------------------------------------\n");
				break;
			} else{
        		current = current->next;
    		}
		}
		if(status == 0){
			printf("Pasien Dengan Nama %s Tidak Ditemukan!", nama);
		}
	}
}

//Average
void usiaRata(struct Node** head_ref){
	struct Node* current = *head_ref;
	int jumlah = 0;
	int i = 0;
	float rata;
	
	if(current == NULL){
		printf("Data Pasien Masih Kosong!");
	} else {
		while (current != NULL) {
    		i++;
    		jumlah = jumlah + current->usia_pasien;
        	current = current->next;
		}
		printf("Rata-rata Usia Pasien : %d", (jumlah/i));        
    	printf("\n");
	}
}

// Print the linked list
void printList(struct Node* node) {
	int total = 0;
	if(node == NULL){
		printf("Data Pasien Masih Kosong!");
	} else {
		printf("--- Daftar Data Pasien ---\n");
		printf("------------------------------------------\n");
	
    	while (node != NULL) {
    		total++;
    		printf("Data Ke-%d\n", total);
       		printf("Kode Pasien : %s\n", node->kode_pasien);
			printf("Nama Pasien : %s\n", node->nama_pasien);
			printf("Usia Pasien : %d\n", node->usia_pasien);
			printf("------------------------------------------\n");
        	node = node->next;
    	}
    	printf("Total Data Pasien : %d", total);
    }
}

// Driver program
int main() {
	char pilihan;
    struct Node* head = NULL;
   
    do{
    	system("cls");
		char pilihan;
	
		pilihan = menu();
		fflush(stdin);
		
		switch(pilihan){
			case '1':
				printf("=====Inset Data Pasien=====\n");
				printf("Kode Pasien : ");
				gets(kode);
				printf("Nama Pasien : ");
				gets(nama);
				printf("Usia Pasien : ");
				scanf(" %d", &usia);
			
				insertAtEnd(&head, kode, nama, usia);
				printf("Data Berhasil Ditambahkan!");
				break;
			case '2':
				printf("Masukkan Nama Pasien Yang Ingin Dicari : ");
				gets(nama);
				searchNode(&head, nama);
				break;
			case '3':
				printf("Masukkan Kode Pasien Yang Ingin Dihapus : ");
				gets(kode);
				deleteNode(&head, kode);
				break;
			case '4':
				findUsia(&head, usiaTermuda(&head), "TERKECIL");
				break;
			case '5':
				findUsia(&head, usiaTertua(&head), "TERBESAR");
				break;
			case '6':
				usiaRata(&head);
				break;
			case '7':
				printList(head);
				break;
			case '8':
				printf("Terimakasih Terlah Menggunakan Aplikasi Ini!");
				return 0;
				break;
			default:
				printf("Tidak Ada Pilihan Seperti Itu!");
				break;
		}
		getch();
	} while (pilihan != '8');
	return 0;
}
