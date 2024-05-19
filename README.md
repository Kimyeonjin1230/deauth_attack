> RadioTap Header?
> 

⇒ 802.11 패킷을 송수신 할 때 도움되는 추가 정보를 담은 헤더. 리틀엔디언 방식

RadioTab 헤더에는 많은 정보가 있지만 중요한거 하나만 말해보자면 airodump-ng 에서 출력해주는 정보 중, Antenna Signal 즉, **안테나의 신호 세기인 dbm 정보**가 담겨 있다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/86d557df-90b0-46f3-b5a5-35ce25c7ba37/Untitled.png)

**version 필드 (1byte)** : Radiotap 헤더의 주요 버전을 나타내며, 현재는 항상 0이다.

**pad 필드 (1byte)**  : 현재 사용되고 있는 필드는 아니라고 한다.

**len 필드  (2byte)** : Radiotap 헤더의 전체 길이를 담고 있다.

**present 필드 (4byte)** :  해당 필드는 비트마스크(BitMask) 형태로 여러 정보가 존재하는지 하지않는지 정의하는 역할을 한다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/1daee452-b4a8-420c-a8d1-780f81e7bd4e/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/d158e31c-fa60-4662-845a-37f50a213c76/Untitled.png)

monitor mode로 바꾸고 snoospy를 실행시켜 준다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/0e7a6b7d-07f5-4099-ba9a-576789f07138/Untitled.png)

그 다음 비콘을 잡는다.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/768f2df2-74e3-42b5-8dab-987cf0667b9f/Untitled.png)

헤더는 8자리 00 00 08 00 00 00 00 00

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/cf4788de-0b29-448e-987f-3e4c4a01d9bf/Untitled.png)

control field : management frame, subtype → 0x0008 

![스크린샷 2024-05-20 04-30-31.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/9a9c9bf0-1fbd-473c-8ccc-11dd6d8247b3/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-05-20_04-30-31.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/4789adca-79a4-4959-b289-ca94134c6b5d/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/ef371de3-7af4-4390-8469-ba150ad1fad1/Untitled.png)

<ap mac>만 명시되는 경우에는 AP broadcast frame을 발생시킨다.

`sudo ./d_attack mon0 <현재 내가 연결되어 있는 우리집 와이파이의 주소>`

![스크린샷 2024-05-20 06-13-01.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/29c5163d-3f31-450c-a9f4-0ecb83517132/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-05-20_06-13-01.png)

![스크린샷 2024-05-20 06-18-17.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/154b5fcc-07bb-447a-a5f5-20c4f38fd5d1/aace6b63-e843-4171-b540-4e4c2e110adb/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-05-20_06-18-17.png)

성공
