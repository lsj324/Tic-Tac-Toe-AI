![다운로드](https://github.com/lsj324/Tic-Tac-Toe-AI/assets/170494075/ae2e551c-c1e2-4ff0-98d6-c28d8a548239)

**프로젝트 소개**

- Tic Tac Toe 게임을 스스로 플레이 할 수 있는 AI를 개발하는 프로젝트입니다.

**진행 순서**

*1. 현재 플레이어의 이동을 결정합니다:*
  - 플레이어 'O' (User)
    - 사용자로부터 입력을 받아 최적의 이동을 결정합니다.
  - 플레이어 'X' (AI)
    - AI 알고리즘을 통해 최적의 이동을 계산합니다.
      
*2. 이동을 수행하고, 보드를 업데이트합니다.*

*3. 승리 여부를 확인합니다:*

  - 현재 플레이어가 승리했는지 검사합니다.
  - 승리 시 게임을 종료하고, 승리 메시지를 출력합니다.
   
*4. 무승부 여부를 확인합니다:*
    
  - 보드에 빈칸이 없는 경우 무승부로 게임을 종료하고, 무승부 메시지를 출력합니다.
    
*5. 게임 종료 후 다시 시작 여부를 묻습니다:*
    
  - 사용자의 입력에 따라 게임을 다시 시작하거나 종료합니다.

**AI 알고리즘**

- 승리 검사 
  - 보드의 각 위치를 순회하며, 현재 심볼로 이동했을 때 승리 여부를 확인합니다.
  - 만약 승리 가능한 이동이 있으면 해당 위치를 반환합니다.
- 상대방의 승리 차단
  - 보드의 각 위치를 순회하며, 상대방 심볼로 이동했을 때 상대방이 승리하는지를 확인합니다.
  - 상대방의 승리를 차단할 수 있는 이동이 있으면 해당 위치를 반환합니다.
- 최적의 점수 계산
  - 각 위치에 대해 이동 후 얻을 수 있는 점수를 계산하고, 가장 높은 점수를 얻을 수 있는 이동을 선택합니다.
  - 무작위로 선택된 동점 이동 위치를 반환합니다.

**기여한 부분**

- Tic Tac Toe 게임 개발
    - 3 x 3 크기의 게임판에 순서대로 O, X 심볼을 원하는 칸에 둘때마다 콘솔창에 새롭게 판이 출력
    - 중복되게 심볼을 배치할 경우 다시 배치할 기회를 제공
- 게임 우승 여부 확인
    - 9칸을 모두 체크하며 각 칸의 가로, 세로, 대각선 3칸에 같은 심볼이 있는지 확인
    - 3개가 연속되게 있다면 게임 승리 출력
- Tic Tac Toe AI 개발
    - AI 차례가 되면 9칸을 모두 돌며 자신의 심볼을 각 칸에 두었을 때 가로, 세로, 대각선에 같은 심볼이 몇개인지 파악
    - 심볼 수에 따라 점수 측정
    - 상대편 심볼 점수도 함께 측정
    - 점수가 가장 큰 칸에 자신의 심볼 배치

**결과**

- AI와 1 vs 1로 경쟁하는 Tic Tac Toe 게임 개발

**시기**

- 2024.07.05 ~ 2024.07.07 (3일)

**실행 영상**


https://github.com/lsj324/Tic-Tac-Toe-AI/assets/170494075/baec71d9-1e05-40a4-afb6-6dca7bd76262

