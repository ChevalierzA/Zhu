import curses
import random

# Setup the curses screen

def main(stdscr):
    # Clear screen
    curses.curs_set(0)  # hide cursor
    stdscr.nodelay(1)   # non-blocking input
    stdscr.timeout(100) # refresh every 100 ms

    sh, sw = stdscr.getmaxyx()
    box = [[3, 3], [sh-3, sw-3]]

    # Draw border
    for i in range(box[0][1], box[1][1]):
        stdscr.addstr(box[0][0], i, '#')
        stdscr.addstr(box[1][0], i, '#')
    for i in range(box[0][0], box[1][0]):
        stdscr.addstr(i, box[0][1], '#')
        stdscr.addstr(i, box[1][1], '#')

    # initial snake and food
    snk_x = sw//2
    snk_y = sh//2
    snake = [
        [snk_y, snk_x],
        [snk_y, snk_x-1],
        [snk_y, snk_x-2]
    ]

    food = [random.randint(box[0][0]+1, box[1][0]-1),
            random.randint(box[0][1]+1, box[1][1]-1)]
    stdscr.addch(food[0], food[1], '*')

    key = curses.KEY_RIGHT

    while True:
        next_key = stdscr.getch()
        key = key if next_key == -1 else next_key

        # Calculate new head
        head = snake[0]
        if key == curses.KEY_DOWN:
            new_head = [head[0] + 1, head[1]]
        elif key == curses.KEY_UP:
            new_head = [head[0] - 1, head[1]]
        elif key == curses.KEY_LEFT:
            new_head = [head[0], head[1] - 1]
        elif key == curses.KEY_RIGHT:
            new_head = [head[0], head[1] + 1]
        else:
            continue

        # Insert new head
        snake.insert(0, new_head)

        # Check if snake hits border or itself
        if (new_head[0] in [box[0][0], box[1][0]] or
                new_head[1] in [box[0][1], box[1][1]] or
                new_head in snake[1:]):
            msg = 'Game Over!'
            stdscr.addstr(sh//2, sw//2 - len(msg)//2, msg)
            stdscr.nodelay(0)
            stdscr.getch()
            break

        if new_head == food:
            food = None
            while food is None:
                nf = [
                    random.randint(box[0][0]+1, box[1][0]-1),
                    random.randint(box[0][1]+1, box[1][1]-1)
                ]
                food = nf if nf not in snake else None
            stdscr.addch(food[0], food[1], '*')
        else:
            tail = snake.pop()
            stdscr.addch(tail[0], tail[1], ' ')

        stdscr.addch(new_head[0], new_head[1], '#')

curses.wrapper(main)
