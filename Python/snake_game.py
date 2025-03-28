import pygame
import random
import sys
from collections import deque

# 初始化pygame
pygame.init()

# 常量集中管理
class Constants:
    WHITE = (255, 255, 255)
    BLACK = (0, 0, 0)
    RED = (255, 0, 0)
    GREEN = (0, 255, 0)
    WINDOW_WIDTH = 800
    WINDOW_HEIGHT = 600
    SNAKE_BLOCK = 20
    BASE_SPEED = 15
    MAX_SPEED = 30
    FONT_NAME = None  # 系统默认字体
    SCORE_FONT_SIZE = 35
    GAME_OVER_FONT_SIZE = 50

# 初始化窗口
window = pygame.display.set_mode((Constants.WINDOW_WIDTH, Constants.WINDOW_HEIGHT))
pygame.display.set_caption("贪吃蛇游戏")

class GameState:
    def __init__(self):
        self.reset()
    
    def reset(self):
        self.snake = deque()
        self.snake_length = 1
        self.head_x = Constants.WINDOW_WIDTH // 2
        self.head_y = Constants.WINDOW_HEIGHT // 2
        self.x_change = 0
        self.y_change = 0
        self.food_pos = self.generate_valid_food_pos()
        self.speed = Constants.BASE_SPEED
        self.game_over = False

    def generate_valid_food_pos(self):
        """生成不与其他游戏元素冲突的食物坐标"""
        while True:
            food = (
                random.randrange(0, Constants.WINDOW_WIDTH - Constants.SNAKE_BLOCK + 1, Constants.SNAKE_BLOCK),
                random.randrange(0, Constants.WINDOW_HEIGHT - Constants.SNAKE_BLOCK + 1, Constants.SNAKE_BLOCK)
            )
            # 检查食物是否与蛇身重叠
            if all(food != (seg[0], seg[1]) for seg in self.snake):
                return food

def game_loop():
    state = GameState()
    clock = pygame.time.Clock()
    
    while True:
        while not state.game_over:
            handle_events(state)
            update_snake(state)
            
            if check_collisions(state):
                state.game_over = True
                break
                
            update_game_state(state)
            render(state)
            clock.tick(state.speed)
        
        handle_game_over(state)

def handle_events(state):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            terminate()
        if event.type == pygame.KEYDOWN:
            handle_controls(event, state)

def handle_controls(event, state):
    controls = {
        pygame.K_LEFT: (-Constants.SNAKE_BLOCK, 0),
        pygame.K_RIGHT: (Constants.SNAKE_BLOCK, 0),
        pygame.K_UP: (0, -Constants.SNAKE_BLOCK),
        pygame.K_DOWN: (0, Constants.SNAKE_BLOCK)
    }
    if event.key in controls:
        new_x, new_y = controls[event.key]
        # 更清晰的转向限制判断
        current_horizontal = state.x_change != 0
        attempt_horizontal = new_x != 0
        if current_horizontal != attempt_horizontal:
            state.x_change, state.y_change = new_x, new_y

def update_snake(state):
    state.head_x += state.x_change
    state.head_y += state.y_change
    state.snake.append([state.head_x, state.head_y])
    # 保持蛇身长度
    while len(state.snake) > state.snake_length:
        state.snake.popleft()

def check_collisions(state):
    # 边界碰撞检测
    if not (0 <= state.head_x < Constants.WINDOW_WIDTH and 
            0 <= state.head_y < Constants.WINDOW_HEIGHT):
        return True
    # 自碰撞检测（跳过头部）
    return any(seg == [state.head_x, state.head_y] for seg in list(state.snake)[:-1])

def update_game_state(state):
    if (state.head_x, state.head_y) == state.food_pos:
        state.food_pos = state.generate_valid_food_pos()
        state.snake_length += 1
        # 带速度上限的加速逻辑
        if state.snake_length % 5 == 0 and state.speed < Constants.MAX_SPEED:
            state.speed += 2

def render(state):
    window.fill(Constants.BLACK)
    # 绘制食物
    pygame.draw.rect(window, Constants.RED, 
                    [*state.food_pos, Constants.SNAKE_BLOCK, Constants.SNAKE_BLOCK])
    # 绘制蛇身
    for seg in state.snake:
        pygame.draw.rect(window, Constants.GREEN,
                        [seg[0], seg[1], Constants.SNAKE_BLOCK, Constants.SNAKE_BLOCK])
    display_score(state.snake_length - 1)
    pygame.display.update()

def display_score(score):
    font = pygame.font.SysFont(Constants.FONT_NAME, Constants.SCORE_FONT_SIZE)
    text = font.render(f"Score: {score}", True, Constants.WHITE)
    window.blit(text, [10, 10])

def handle_game_over(state):
    while state.game_over:
        window.fill(Constants.BLACK)
        show_game_over_message(state.snake_length - 1)
        pygame.display.update()
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                terminate()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    terminate()
                elif event.key == pygame.K_c:
                    state.reset()
                    return

def show_game_over_message(score):
    font = pygame.font.SysFont(Constants.FONT_NAME, Constants.GAME_OVER_FONT_SIZE)
    messages = [
        "Game Over! Press Q-Quit or C-Play Again",
        f"Your Score: {score}"
    ]
    for i, msg in enumerate(messages):
        text = font.render(msg, True, Constants.RED if i == 0 else Constants.WHITE)
        window.blit(text, [Constants.WINDOW_WIDTH//6, Constants.WINDOW_HEIGHT//3 + i*50])

def terminate():
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    game_loop()
