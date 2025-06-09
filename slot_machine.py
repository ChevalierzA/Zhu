import random

SYMBOLS = ['🍒', '🔔', '🍋', '⭐', '7']


def spin_reel():
    return random.choice(SYMBOLS)


def check_win(reels):
    if reels.count(reels[0]) == 3:
        return 50
    if len(set(reels)) == 2:
        return 20
    return 0


def main():
    coins = 100
    print('欢迎来到老虎机游戏! 每次投注 10 金币. 输入 q 退出.')
    while coins >= 10:
        cmd = input('按 Enter 拉杆，或输入 q 退出: ')
        if cmd.lower() == 'q':
            break
        coins -= 10
        reels = [spin_reel() for _ in range(3)]
        print(' | '.join(reels))
        reward = check_win(reels)
        if reward:
            print(f'恭喜获胜！奖励 {reward} 金币')
            coins += reward
        else:
            print('很遗憾，未中奖')
        print(f'剩余金币: {coins}')
    print('游戏结束, 欢迎下次再来!')


if __name__ == '__main__':
    main()
