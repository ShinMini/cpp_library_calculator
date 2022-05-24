## 도서관 좌석 관리 시스템

![Alt text](./imgfile/main/main-menu.png?raw=true "main_menu")

### 프로그램 기능 
1. 도서관 좌석 현황 체크 가능. 
2. 도서관 좌석에 사람이 앉아있는지 체크가능 => 30분 간격 좌석 테스트(압력 감지) 
	1. 기준 무게 이상인지(10kg, ex) 가방 무게 이상)
	2. 10분이후, 무게 변화 없는지 -> 사람이라면, 적어도 2kg 이상의 오차 생성. => 다리 위치에 따른 무게 변화 2kg(임의의 값) 폭 감지
	3. 10분간격 체크하며, 자리 비움 상태 체크, 자리비움 체크 3회 이상일경우 자동 퇴실 처리 및 자리 비움 상태로 변경. 
3. 도서관 좌석에 사람이 앉아있는지 랜덤값을 넣어 프로그램 상태 점검 가능 및 오류 검출 가능. 

### 1. 프로그램 실행 시

* 기본 메뉴 등장
	1. 좌석 생성(사용자 지정)
		1. 새로운 좌석 배열 생성
		2. 기존 저장해둔 좌석 배열 가져오기

![Alt text](./imgfile/M_1/select1.png?raw=true "first_menu")

	2. 프로그램 테스트
		1. 랜덤 값을 지정해 테스트 실행. 
		- 최대 및 최소 좌석 수 입력
		- 자동으로 사용가능 및 불가능 좌석 생성, 
		- 사용 가능 및 불가능 좌석 user interface에 표기

![select 2](./imgfile/M_2/select2.png?raw=true "second_menu")

	* 잘못 된 값을 입력했을 경우 

![wrong](./imgfile/M_2/select2-wrong1.png?raw=true "second_wrong_case")

	* 정상적으로 값을 입력했을 경우 

![wrong](./imgfile/M_2/select2-success.png?raw=true "second_success_case")

	3. 프로그램 종료
		- 프로그램 종료 기능. 
	

