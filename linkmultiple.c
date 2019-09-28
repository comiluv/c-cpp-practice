/* 
사용자 지정 header를 사용한 예
vscode에서는 빌드할때 tasks.json 파일에 .c 파일들을 써줘야 함
 */
#include <stdio.h>
#include "human.h"
int main() {
  struct Human Lee = Create_Human("Lee", 40, MALE);

  Print_Human(&Lee);

  return 0;
}