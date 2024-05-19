# RadioTap Header? 
: 802.11 패킷을 송수신 할 때 도움되는 추가 정보를 담은 헤더. 리틀엔디언 방식. RadioTab 헤더에는 많은 정보가 있지만 중요한거 하나만 말해보자면 airodump-ng 에서 출력해주는 정보 중, Antenna Signal 즉, 안테나의 신호 세기인 dbm 정보가 담겨 있다.

lan 카드를 monitor mode로 바꿔준다.

`ifconfig <old interface> down`

`ip link set <old interface> name <new interface>` //정신없던 인터페이스에서 mon0라는 이름으로 바꿔주겠다.

`ifconfig <new interface> up`

`ifconfig mon0 down`
`iwconfig mon0 mode monitor`
`ifconfig mon0 up`

![스크린샷 2024-05-20 00-51-12](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/88bd056d-9ae4-4c44-b9ba-46ff80d9261f)

snoospy로 비콘이 정상으로 작동하는지 확인하였다.(생략가능)

![스크린샷 2024-05-20 03-56-39](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/1f15bbd5-07eb-4ce0-82b8-1bee1bdfb5f4)

와이어샤크로 헤더부부분의 패킷을 하나하나 프레임으로 담아줬다.

[참고] https://blog.naver.com/nms200299/222267279476
![스크린샷 2024-05-20 04-16-30](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/a241fe6f-4e57-4b35-b167-f8039c01a4e5)
