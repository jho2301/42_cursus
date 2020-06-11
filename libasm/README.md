# Libasm

## 레지스터
![](https://github.com/gurugio/book_assembly_8086_ko/raw/master/assets/cpu.gif)
- ax (acumulator): 적산하는 레지스터
- bx (base address):  메모리 주소 계산 레지스터
- cx (counter): 반복문 카운팅시 사용 (5번반복 -> 5, 4, 3, 2, 1)
- dx (data): 계산의 결과 값 저장 / 메모리에서 읽어온 데이터 저장
- si (source index): 메모리 복사 등에서 원본 데이터의 주소를 저장
- di (Destination Index): 메모리 복사 등에서 목적지의 주소를 저장
- bp (base pointer): 스택의 베이스 주소
- sp (stack pointer): 스택의 현재 주소

## 세그먼트 레지스터
- CS: 현재 프로그램이 저장된 세그먼트의 주소가 저장됩니다.

- DS: 현재 사용하는 데이터가 저장된 세그먼트의 주소가 저장됩니다.

- ES: 별도의 용도는 없고 필요할 때마다 원하는 메모리 위치의 세그먼트 주소를 저장합니다.

- SS: 스택이 있는 세그먼트의 주소가 저장됩니다.

## 플래그 레지스터
- Carry Flag (CF) - 부호없는 정수가 overflow일경우 플래그값은 1로 설정됩니다. 무슨 말이냐면 al에 255를 넣고 1을 더하는 연산을 하는 경우에 결과값이 범위가 8비트 범위 0 ~ 255를 넘게되고 이런 상태를 overflow라고 부릅니다. overflow가 아닌경우에는 플래그 값은 0으로 남아있습니다.

- Zero Flag (ZF) - 결과값이 0일때 1로 설정됩니다. 같은 레지스터끼리 아니면 같은 값을 가진 레지스터끼리 빼기를 하면 0이 되지요. 결과값이 0이 아닐경우 플래그 값은 0이됩니다.

- Sign Flag (SF) - 결과값이 음수일경우 1이 됩니다. 양수일때는 0이 되고요.

- Overflow Flag (OF) - 부호 있는 정수끼리의 연산에서 overflow일경우 1이 됩니다. 예를들어 100 + 50할 경우입니다.(결과값 범위가 -128...127이 아니므로) Carry Flag와는 다릅니다.

- Parity Flag (PF) - 비트값이 1인것이 짝수이면 1로 설정하고, 홀수이면 0으로 설정한다. 결과값이 word이고, 8 low bit이어도 분석을 한다.

- Auxiliary Flag (AF) - 부호 없는 정수 nibble(4 비트)이 overflow일경우 1로 설정한다.

- Interrupt enable Flag (IF) - CPU가 외부 장치에 의해 인터럽트를 반응할때 1로 설정한다.

- Direction Flag (DF) - 이 플래그는 명령어에 의해 data chain이 처리 될때 사용된다. 프로세싱이 메모리 앞 번지에서 뒷번지로 진행될때는 0로 설정되고 프로세싱이 메모리 뒷번지에서 앞번지로 진행 될때는 1로 설정된다.

## 연산 : opcode
- test -  레지스터의 값은 바꾸지 않는 and. 플래그 레지스터값만 바뀐다.
- mul - 부호를 고려하지 않는 곱하기 (16비트 * 16비트 = 32비트 이므로 연산 시, 보이지 않는 레지스터를 추가로 사용함)
- imul - 부호를 생각하는 곱하기
- cmp - 레지스터의 값은 바꾸지 않는 sub. 플래그 레지스터 값만 바꾼다.
### jump 연산

| 명령어 | 설명 | 조건 | 반대명령어 |
| :--- | :--- | :--- | :--- |
|jz, je|	0일때(같을때) 점프	|zf=1|	jnz,jne
|jc, jb, jnae|      각각 캐리가 생겼을때, 작을때, 크거나 같지 않을때 점프    cf=1   | jnc, jnb, jae  |
|js           |   계산 결과 부호 비트가 켜졌을 때 점프  |  sf=1 |   jns  |
|jo |   오버플로우가 발생했을 때 점프   | of=1   | jno | 
|jpe, jp|    Parity Even 상태가 되었을 때 점프  |  pf=1  |  jpo  |
|jnz, jne|    0이 아니거나 같지 않을 때 점프  |  zf=0  |  jz, je | 
|jnc, jnb, jae|    캐리가 없을때, 작지 않을때, 크거나 같을 때 점프  |  cf=0 |   jc, jb, jnae  |
|jns|    부호 비트가 0일 때 점프  |  sf=0  |  js | 
|jno|    오버플로우가 아닐 때 점프  |  of=0  |  jo  |
|jpo, jnp|    Parity Odd 상태일 때 점프 |   pf=0  |  jpe, jp  |

부호있는 숫자들을 비교해서 점프하는 명령어는 다음 테이블에 있습니다.

|명령어  |  설명   | 조건  |  반대 명령어  |
| :--- | :---   | :---  | :--- |
|JE , JZ |   Jump if Equal \(=\). Jump if Zero.  |  ZF = 1   | JNE, JNZ  |
|JNE , JNZ |   Jump if Not Equal \(&lt;&gt;\). Jump if Not Zero.  |  ZF = 0  |  JE, JZ  |
|JG , JNLE |   Jump if Greater \(&gt;\). Jump if Not Less or Equal \(not &lt;=\).   | ZF = 0 and SF = OF  |  JNG, JLE  |
|JL , JNGE |   Jump if Less \(&lt;\). Jump if Not Greater or Equal \(not &gt;=\).  |  SF &lt;&gt; OF  |  JNL, JGE  |
|JGE , JNL |   Jump if Greater or Equal \(&gt;=\). Jump if Not Less \(not &lt;\).  |  SF = OF   | JNGE, JL  |
|JLE , JNG |   Jump if Less or Equal \(&lt;=\). Jump if Not Greater \(not &gt;\).  |  ZF = 1 or SF &lt;&gt; OF   | JNLE, JG|

&lt;&gt;는 같지 않다는 표시입니다. 별로 설명하게 없습니다. 크냐 작냐 뿐이니까요. 참고로 크지 않다는 작거나 같다는 것이고 작지 않다는 크거나 같다는 것입니다. &gt; 의 반대는 &lt;= 이라는거 당연하지만 가끔 =을 빼먹으면 골치아픈 버그가 생깁니다.

##부호없는 숫자를 비교해서 점프하기

|명령어  |  설명   | 조건  |  반대 명령어  |
| :--- | :---   | :---  | :--- |
|JE , JZ    |Jump if Equal \(=\). Jump if Zero.  |  ZF = 1  |  JNE, JNZ  |
|JNE , JNZ   | Jump if Not Equal \(&lt;&gt;\). Jump if Not Zero.  |  ZF = 0  |  JE, JZ  |
|JA , JNBE  |  Jump if Above \(&gt;\). Jump if Not Below or Equal \(not &lt;=\).  |  CF = 0 and ZF = 0  |  JNA, JBE | 
|JB , JNAE, JC  |  Jump if Below \(&lt;\). Jump if Not Above or Equal \(not &gt;=\). Jump if Carry.   | CF = 1  |  JNB, JAE, JNC  |
|JAE , JNB, JNC  |  Jump if Above or Equal \(&gt;=\). Jump if Not Below \(not &lt;\). Jump if Not Carry.   | CF = 0  |  JNAE, JB  |
|JBE , JNA  |  Jump if Below or Equal \(&lt;=\). Jump if Not Above \(not &gt;\).  |  CF = 1 or ZF = 1  |  JNBE, JA|


## from 16bits to x64  

nasm이냐 at&t냐 같은 어셈블러나 문법에 상관없이 운영체제가 만든 규약이다 함수 인자가 6개 이내면 RDI, RSI, RDX, RCX, R8, R9에 순서대로 저장한다 6개가 넘으면 스택에 저장한다
RAX, R10, R11는 호출되는 함수가 맘대로 써도 된다. 따라서 함수 호출전에 스택에 저장하고 함수 호출 후에 스택에서 원래 값을 꺼내는 절차가 필요하다.
반환값은 RAX, RDX에 순서대로 저장한다. C언어는 반환값이 1개이므로 보통 RAX를 사용합니다. 어셈블리로 만든 함수를 어셈블리에서 호출하면 반환값을 2개이상 만들 수 있겠네요.
컴파일러에 따라 128비트 반환값을 지원하기도 합니다. 그러면 RAX만으로 표현이 안되니까 두개의 레지스터를 사용합니다. RAX:RDX를 사용할 수도 있고, 그건 컴파일러마다 다르겠지요.
부동소수점 인자를 전달하는데도 규칙이 있다. 어떤 규칙인지는 일일이 설명안해도 아시겠지요?
void foo(long a, double b, int c) 이런 함수를 호출하게되면 a는 RDI에, b는 XMM0, c는 ESI에 저장된다. c가 왜 esi냐면 int가 32비트라서 그렇습니다.
