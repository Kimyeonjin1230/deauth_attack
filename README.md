# RadioTap Header? 
: 802.11 패킷을 송수신 할 때 도움되는 추가 정보를 담은 헤더. 리틀엔디언 방식. RadioTab 헤더에는 많은 정보가 있지만 중요한거 하나만 말해보자면 airodump-ng 에서 출력해주는 정보 중, Antenna Signal 즉, 안테나의 신호 세기인 dbm 정보가 담겨 있다.

lan 카드를 monitor mode로 바꿔준다.

`ifconfig <old interface> down`

`ip link set <old interface> name <new interface>` //정신없던 인터페이스에서 mon0라는 이름으로 바꿔주겠다.

`ifconfig <new interface> up`

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
`ifconfig mon0 down`

`iwconfig mon0 mode monitor`

`ifconfig mon0 up`

![스크린샷 2024-05-20 00-51-12](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/88bd056d-9ae4-4c44-b9ba-46ff80d9261f)

snoospy로 비콘이 정상으로 작동하는지 확인하였다.(생략가능)

![스크린샷 2024-05-20 03-56-39](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/1f15bbd5-07eb-4ce0-82b8-1bee1bdfb5f4)

와이어샤크로 헤더부부분의 패킷을 하나하나 프레임으로 담아줬다.

[참고] https://blog.naver.com/nms200299/222267279476
![스크린샷 2024-05-20 04-16-30](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/a241fe6f-4e57-4b35-b167-f8039c01a4e5)

이 6바이트는 모든 랜카드에 해당하는 것이라서 리틀엔디언 방식이 적용이 안되는 것 같다.(?) radiotab은 리틀엔디언 방식이다.
![스크린샷 2024-05-20 04-25-39](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/6de57e1c-521a-49c5-bcce-e118e871bfa0)

야무지게 담아준다.
![스크린샷 2024-05-20 04-30-31](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/9c2fdf23-6cb4-4fef-83bc-83d76b3fb28c)
![스크린샷 2024-05-20 06-46-37](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/c46a71dd-02b5-48f3-a4ec-4300ab261d9a)

`sudo ./d_attack mon0 00:07:89:63:**:**` (우리집 와이파이)
![스크린샷 2024-05-20 06-13-01](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/a91352f6-3e55-4b0d-a574-478e3889c0fc)

![스크린샷 2024-05-20 06-18-17](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/cfaeb9fc-9b82-4a7c-a04b-df38fbc98b08)

성공이다. 연결해제됐다. ctrl+c누를때까지 연결이 안된다.


https://living-tortellini-77c.notion.site/repo-deauth-attack-b9d6528ea44d45f2af383317838e1e39?pvs=4




*참조*
https://blog.naver.com/nms200299/222267279476

https://www.radiotap.org/
