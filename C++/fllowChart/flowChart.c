#include<stdio.h>
void depth_2_1() {
	printf("inside depth_2_1 \n");


}
void depth_2_2() {
	fprintf(stderr, "inside path \n");
}
void depth_1() {
	depth_2_1();
	depth_2_2();

	printf("inside path\n");
}
int main() {
	depth_1();
}