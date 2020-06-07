# net what

 ### What is an IP address ?

- https://ko.wikipedia.org/wiki/IP_%EC%A3%BC%EC%86%8C

- https://en.wikipedia.org/wiki/IP_address

- 컴퓨터 네트워크에서 장치들이 서로를 인식하고 통신을 하기 위해서 사용하는 특수한 번호
  
- [IPv4 주소](https://namu.wiki/w/IP)는 4개의 [바이너리 8자리수](https://namu.wiki/w/2진법)로 이루어져 총 32비트로 구성되어 있다. 예를 들어 192.168.0.1은 1100 0000 . 1010 1000 . 0000 0000 . 0000 0001 로 표현된다. IP 주소는 네트워크 부분과 호스트 부분으로 나누어진다. 하나의 로컬 네트워크란 하나의 라우터를 거쳐가는 여러 개의 호스트들이 연결된 브로드캐스트(브로드캐스팅은 송신 호스트가 전송한 데이터가 네트워크에 연결된 모든 호스트에 전송되는 방식을 의미한다)영역이다. 즉, 어떤 네트워크에서 한 노드가 브로드캐스트를 했을 때 그 네트워크의 모든 노드가 신호를 받았다면 그 네트워크는 하나의 네트워크라고 볼 수 있다. 호스트란 그냥 각각의 노드(PC, 스마트폰, 태블릿 등)들이다.  IPv6는 브로드 캐스트 방법을 구현하지 않았다
  
  > IPv4 : 255.255.255.255  //Classless Inter-Domain Routing(CIDR) notation  
  > IPv6: 2001:0db8:00:0000:8a2e:0370:7334

- Feature

  - identify the host
  - addressing to locate the host

- IP address assignment can be **static** or **dynamic**

### What is a Netmask ?

![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/Subnetting_Concept-en.svg/1200px-Subnetting_Concept-en.svg.png)





The practice of dividing a network into two or more networks is called **subnetting**.

**네트워크 성능 보장, 자원을 효율적으로 분배하기 위해 네트워크 영역과 호스트 영역을 쪼개는 작업**

**너무 큰 브로드캐스트 도메인은 네트워크 환경에서 패킷전송을 느리게하고 성능저하를 발생시킨다.**

 Computers that belong to a subnet are addressed with an identical [most-significant bit](https://en.wikipedia.org/wiki/Most-significant_bit)-group in their [IP addresses](https://en.wikipedia.org/wiki/IP_address). 

This results in the logical division of an IP address into two fields, the *network number* or *routing prefix* and the *rest field* or *host identifier*. The *rest field* is an identifier for a specific [host](https://en.wikipedia.org/wiki/Host_(network)) or network interface.

- Why? 
  - saturation of available address with IPv4
- 서브넷 마스크를 계산할 때는  AND를 사용한다.

### What is the subnet of an IP with Netmask ?

- 만약 비트길이가 24 라면 IP주소에 255.255.255.0를 AND연산 한 것이 IP의 서브넷 네트워크가된다.

###  What is the broadcast address of a subnet ?

- 브로드캐스트 주소는 어드레스 주소중 가장 큰 수이다.

- **브로드캐스트 주소 구하는 법**

  IP address: 192.168.16.1

  Subnet mask: 255.255.255.224

  **1) Subnet mask에 invert (1의 보수)를 취한다.**

    255.255.255.224 => 11111111.11111111.11111111.11100000

    이것을 invert하면 00000000.00000000.00000000.00011111

  **2) Invert한 subnet과 IP address를 Logical OR를 한다.**

   192.168.16.1   => 11000000.10101000.00010000.00000001

   Invert한 서브넷 =>  00000000.00000000.00000000.00011111

   결과는       =>  11000000.10101000.00010000.00011111 => 192.168.16.31

### What are the different ways to represent an ip address with the Netmask ?

1.  255.255.255.255/24
2. IP address :255.255.123.42 Subnet Mask :255.255.255.0

### What are the differences between public and private IPs? ###

- https://www.codns.com/b/B05-104

- **사설 IP는 내부 네트워크 ( 예, 공유기 내부 네트워크 ) 상에서만 사용되는 주소로 인터넷상에서는 사용할 수 없는 IP주소입니다. 반면 공인 IP는 ICANN. [인터넷 진흥원(KISA)](https://www.kisa.or.kr/)등의 IP 주소 할당 공인기관에서 할당한 인터넷 상에서 사용할 수 있는 IP주소를 말합니다.**

- **사설 IP**는 네트워크(Network) 안에서 사용되는 주소.( 내부적으로 사용되는 고유한 주소 )로 사설 IP는 하나의 네트워크 안에서 유일하며. 사설 IP(private IP)는 이 이름에서 보듯이 인터넷상에서 확인할 수 없고, 내부 네트워크에서만 사용 가능한 IP를 말합니다.

  가정이나, 소규모 사무공간에서 공유기 / 라우터 등의 장비가 하나의 공인 IP를 할당 받고 NAT방식을 통해 여러 컴퓨터가 나누어 쓰는 방식으로 사용될 때 주로 사용되며, 아래의 표와 같은 B, C class의 사설IP 대역이 많이사용됩니다.-

- **공인 IP** (Public IP Address)는 공인이 된 IP를 뜻(전세계에서 유일)하며. 전세계적으로 ICANN이라는 기관이 국가별로 사용할 IP 대역을 관리하고 우리 나라는 [인터넷 진흥원(KISA)](https://www.kisa.or.kr/)에서 우리나라 내에서 사용할 주소를 관리하고 있습니다. 

  따라서, 임의로 아무 IP 주소나 내 컴퓨터에 지정한다고 인터넷이 되는 것이 아니라 할당 받은 주소를 부여해야만 인터넷에 접속할 수 있게 됩니다.

### What is a class of IP addresses?

<img src="https://t1.daumcdn.net/cfile/tistory/99068D495BE8101D34" alt="ip class" style="zoom:150%;" />

- https://limkydev.tistory.com/168

- 어떻게 네트워크 주소와 호스트 주소를 구분할 수 있을까요? 바로 클래스 때문입니다. 203.240.100.1 IP가 C클래스 이기 때문에 203.240.100 은 네트워크 주소이고, 1은 호스트 주소란 사실을 알아낸 것입니다. 

- 클래스 : **네트워크 크기에 따른 구분**

-  IP주소 클래스의 종류에는 총 5개가 있습니다. A클래스, B클래스, C클래스, D클래스 E클래스 

  - | class |                             설명                             |
    | ----- | :----------------------------------------------------------: |
    | A     | **IP주소  맨 앞자리 수가 항상 0 인 경우가 바로 A클래스입니다.** (0.0.0.0 ~ 127.255.255.255) |
    | B     | **B클래스는 반드시 10으로 시작합니다.** (128.0.0.0 ~ 191.255.255.255) |
    | C     | **C클래스는 반드시 110으로 시작합니다.** (192.0.0.0 ~ 223.255.255.255) |                                                              |

### What is TCP(Transmission Control Protocol ) ?

- [protocols](https://en.wikipedia.org/wiki/Communications_protocol) of the [Internet protocol suite](https://en.wikipedia.org/wiki/Internet_protocol_suite). 

- connection oriented (  connection between client and server is established (passive open) before data can be sent. )

- UDP와의 큰 차이점은 연결설정단계를 거치냐 안거치느냐 유무

- [reliable](https://en.wikipedia.org/wiki/Reliability_(computer_networking)), ordered, and [error-checked](https://en.wikipedia.org/wiki/Error_detection_and_correction) delivery of a stream of [octets](https://en.wikipedia.org/wiki/Octet_(computing))

- three-way handshake (active open), [retransmission](https://en.wikipedia.org/wiki/Retransmission_(data_networks)), and error-detection 

-  host-to-host communication

- 3way handshake

  **[STEP 1]**

  A클라이언트는 B서버에 접속을 요청하는 SYN 패킷을 보낸다. 이때 A클라이언트는 SYN 을 보내고 SYN/ACK 응답을 기다리는SYN_SENT 상태가 되는 것이다.

   

  **[STEP 2]** 

  B서버는 SYN요청을 받고 A클라이언트에게 요청을 수락한다는 ACK 와 SYN flag 가 설정된 패킷을 발송하고 A가 다시 ACK으로 응답하기를 기다린다. 이때 B서버는 SYN_RECEIVED 상태가 된다.

   

  **[STEP 3]**

  A클라이언트는 B서버에게 ACK을 보내고 이후로부터는 연결이 이루어지고 데이터가 오가게 되는것이다. 이때의 B서버 상태가 ESTABLISHED 이다.

  위와 같은 방식으로 통신하는것이 신뢰성 있는 연결을 맺어 준다는 TCP의 3 Way handshake 방식이다.

  

  출처: https://mindnet.tistory.com/entry/네트워크-쉽게-이해하기-22편-TCP-3-WayHandshake-4-WayHandshake [Mind Net]

### What is UDP(User Datagram Protocol) ?

- https://searchnetworking.techtarget.com/definition/UDP-User-Datagram-Protocol

-  used primarily for establishing low-latency and loss-tolerating connections 

- process-to-process communication

- connectionless protocol 

- ![https://cdn.ttgtmedia.com/rms/onlineimages/whatis-tcp_vs_udp-f.png](https://cdn.ttgtmedia.com/rms/onlineimages/whatis-tcp_vs_udp-f.png)

  

### What are the network layers ?

- OSI레이어 3계층 
- host 2 host 통신  
- 전송단위 packet (datagram) 
-  주소 logical address  
- 프로토콜 IP, routing protocol (RIP, OSIF), ARP

###  What is the OSI model ?

layer |주기능|전송단위|주소|프로토콜의 예
--|--|--|--|--
Application | | msg / data /info ||HTTP, FTP, DNS, DHCP
presentation | |  ||
session | |  |host address|
transport | process 2 process (port 2 port) | segment |port address|TCP, UDP
network | host 2 host (end node) | packet (datagram) |logical address IP|IP, routing protocol (RIP, OSIF), ARP
data link | node 2 node (hop) | frame |physical address MAC|point to point protocol, IEEE 802.3, IEE802.11 ATM, HDLC, RARP
physical |  | bit ||



### What is a DHCP server   (Dynamic Host Configuration Protocol)? 

- IP 를 필요로 하는 컴퓨터에게 자동으로 할당해서 사용할 수 있도록 해주고, 사용하지 않으면 반환받아 다른 컴퓨터가 사용할 수 있도록 해주는 것

- Application Layer

- IP 동적 할당

- DHCP서버는 일정한 IP 대역을 갖고 있는데 이를 분배해줌 

  - **Lease**

    - 임대 기간은  8일 (Default)

    - **1. Discover.**

      IP 주소가 할당되지 않은 클라이언트는 MAC 주소를 기반으로 IP 주소를 받아오기 위해 로컬 네트워크에 Discover 패킷을 Broadcast 한다. 이 Discover 패킷에는 IP 주소가 필요한 호스트의 MAC 주소가 담겨져 있어서 DHCP 서버가 응답할 때 패킷을 수신할 수 있게 된다.

      **2. Offer.**

      DHCP 서버가 Discover 패킷을 받게 되면, DHCP 서버는 Offer 패킷을 Broadcast한다. 이때, MAC 주소에 아까 Discover 패킷을 보낸 호스트의 MAC 주소를 적어서 보낸다.  이를 통해 식별가능!

      **3. Request.**

      해당 호스트는 해당 네트워크에 DHCP 서버가 있다고 판단, Request 패킷을 Broadcast한다

      **4. ACK.**

      DHCP 서버는 Request 패킷을 받으면 자신의 IP 임대 풀에서 할당 가능한 IP 주소를 찾는다. 이 임대 풀에서 가장 앞에 있는 IP 주소부터 할당하게 된다. 역시 Broadcast로 전송되며, 호스트가 이 패킷을 정상적으로 받았다면 IP 주소가 할당된다.

  - **Renewel**

    - 임대 갱신은 임대 기간이 50% 남았을 때 시도된다. 이 때, 갱신에 성공하면 갱신된 시간으로 부터 임대 기간이 다시 차게 된다.  갱신에 실패하게 된다면 87.5%의 시간이 지났을 때 다시 갱신을 시도한다. 
    - Discover, Offer 과정을 제외한 Request, ACK 과정만을 DHCP 서버와 1:1로 Unicast 통신

  - **Release**

- 보통 [라우터](https://namu.wiki/w/라우터) 장비에 해당 기능이 탑재

- DHCP server : IP 를 보유하고, 원하는 가입자에게 IP 를 분배해주는 역할.

###  What is a DNS server and the DNS protocol  (Domain Name system)?

- 영문/한글 주소를 IP 네트워크에서 찾아갈 수 있는 [IP](https://namu.wiki/w/IP)로 변환해 준다.

- 리소스 레코드(Resource record)를 가지며, 이 리소스 레코드는 A, AAAA, CNAME, NS, MX, SPF, [PTR](https://namu.wiki/w/리버스 도메인) 등으로 이루어져있다.

- Forward Zone(도메인 이름 → IP)과 Reverse Zone(IP → 도메인 이름)을 가진다. 주로 Forward Zone에는 도메인을 구성하는 호스트에 대한 정보를, Reverse Zone에는 DNS 서버 [자기 자신에 대한 정보](https://namu.wiki/w/재귀함수)를 기록한다.

- DNS 서버에 질의하면 돌아오는 응답은 Authoritative answer와 Non-authoritative answer로 나뉜다.

-non athoritative answer
-  | 순서 | 질의자                                             | 응답자                                                       | 종류 | 쿼리의 내용                                          |
  | ---- | -------------------------------------------------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
  | 1    | 클라이언트                                         | [ISP](https://namu.wiki/w/인터넷 서비스 제공사업자)[[8\]](https://namu.wiki/w/DNS#fn-8) | 질의 | "[www.daum.net](https://namu.wiki/w/Daum)"           |
  | 2    | ISP의 DNS 서버에서 자신의 레코드를 확인 **(실패)** |                                                              |      |                                                      |
  | 3    | ISP                                                | **.**[[9\]](https://namu.wiki/w/DNS#fn-9)                    | 질의 | net DNS 서버의 도메인 이름                           |
  | 4    | 응답                                               | net DNS 서버의 IP 주소                                       |      |                                                      |
  | 5    | ISP                                                | net                                                          | 질의 | daum.net DNS 서버의 도메인 이름                      |
  | 6    | 응답                                               | daum.net DNS 서버의 IP 주소                                  |      |                                                      |
  | 7    | ISP                                                | daum.net                                                     | 질의 | "[www.daum.net](https://namu.wiki/w/Daum)"           |
  | 8    | 응답                                               | "[www.daum.net](https://namu.wiki/w/Daum)"의 IP 주소         |      |                                                      |
  | 9    | 클라이언트                                         | ISP                                                          | 응답 | "[www.daum.net](https://namu.wiki/w/Daum)"의 IP 주소 |

###  What are the rules to make 2 devices communicate using IP addresses ?

-  Minimum configuration for communicating two addresses using the IP:
  Client
  -> Gateway 
  -> Internet 
  -> Gateway 
  -> Server

### How does routing work with IP ?

- router는 Lyaer 3계층을 대표하는 장비이며 자신이 포함되지 않은 외부 네트워크로 통신시 사용되는 장비이다.
- 라우터는 라우팅 테이블을 갖고 있다.
- 라우팅 테이블은 목적지인 IP와(key) 목적지로 향하는 다음 라우터인 next hop (node)에 대한 주소를(value) 갖고있다.
- 특정 목적지로 향하는 패킷은 수 많은 라우터를 거치며 목표IP 에 대한 정보만 가진채 next hop으로 계속해서 이동한다 .

###  What is a default gateway for routing ?

- 게이트웨이는 개념인데 외부 네트워크와 통신을 하는 것을 게이트웨이라 말한다. 라우터 스위치 모두 게이트웨이가 될 수 있다.

### What is a port from an IP point of view and what is it used for when connecting to another device ?

- 포트 = 프로세스 
- 호스트 내부에도 네트워크 통신을 원하는 여러 프로세스가 존재한다

