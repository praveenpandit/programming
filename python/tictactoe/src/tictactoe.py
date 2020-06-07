import random


class TicTacToe(object):
    def __init__(self, player1='PLAYER-1', player2='PLAYER-2', gameType='STANDARD', oponent='HUMAN'):
        self.board = ['-' for i in range(9)]
        self.player1 = player1
        self.player2 = oponent
        self.gameType = gameType
        self.oponent = oponent
        if self.oponent == 'COMPUTER':
            self.player2 = oponent

    def __str__(self):
        print('\n' + '*' * 20)
        print('  TIC-TAC-TOE BOARD')
        print('*' * 20, end='')
        for i in range(len(self.board)):
            if (not i % 3):
                print('', end='\n   ')
            print(i.__str__() + '|' + self.board[i].__str__() + '  ', end='')
        return ""


class Standard(TicTacToe):
    def setBoard(self, loc, player, value='X'):
        if loc < 0 or loc > 8:
            return False
        elif self.board[loc] == '-':
            if(self.player1 == player):
                self.board[loc] = 'X'
            else:
                self.board[loc] = 'O'
            return True
        return False

    def __isMatch(self, series, value='X'):
        for i in range(len(series)):
            flag = True
            for j in range(3):
                flag = flag and True if self.board[series[i]
                                                   [j]] == value else False
            if flag:
                return True
        return False

    def isWin(self, value='X'):
        rows = [[0, 1, 2], [3, 4, 5], [6, 7, 8]]
        cols = [[0, 3, 6], [1, 4, 7], [2, 5, 8]]
        diag = [[0, 4, 8], [2, 4, 6]]
        if (self.__isMatch(rows, value) or self.__isMatch(cols, value) or self.__isMatch(diag, value)):
            print(self.player1 + " has won the macth!!!") if value == 'X' else print(
                self.player2 + " has won the macth!!!")
            return True
        return False


class Decimal(TicTacToe):
    def setBoard(self, loc, player, value=0):
        if loc < 0 or loc > 8:
            return False
        elif self.board[loc] == '-' and value not in self.board:
            if(self.player1 == player):
                if value in [1, 3, 5, 7, 9]:
                    self.board[loc] = value
                else:
                    return False
            else:
                if value in [2, 4, 6, 8]:
                    self.board[loc] = value
                else:
                    return False
            return True
        return False

    def __isMatch(self, series):
        for i in range(len(series)):
            player1_flg = True
            player2_flg = True
            sum = 0
            for j in range(3):
                try:
                    sum += int(self.board[series[i][j]])
                except ValueError or TypeError:
                    sum += 0
                if self.board[series[i][j]] not in [1, 3, 5, 7, 9]:
                    player1_flg = player1_flg and False
                if self.board[series[i][j]] not in [2, 4, 6, 8]:
                    player2_flg = player2_flg and False
            # print(player1_flg, player2_flg, sum)
            if (player1_flg ^ player2_flg) and sum >= 15:
                return True
        return False

    def isWin(self, value='1'):
        rows = [[0, 1, 2], [3, 4, 5], [6, 7, 8]]
        cols = [[0, 3, 6], [1, 4, 7], [2, 5, 8]]
        diag = [[0, 4, 8], [2, 4, 6]]
        if (self.__isMatch(rows) or self.__isMatch(cols) or self.__isMatch(diag)):
            print(self.player1 + " has won the macth!!!") if value == '1' else print(
                self.player2 + " has won the macth!!!")
            return True
        return False


class Human(Standard, Decimal):
    def setBoard(self, loc, player, value='X'):
        if self.gameType == 'STANDARD':
            return Standard.setBoard(self, loc, player, value)
        elif self.gameType == 'DECIMAL':
            return Decimal.setBoard(self, loc, player, value)


class Computer(Standard, Decimal):
    def setBoard(self, loc, player, value='X'):
        if self.gameType == 'STANDARD':
            return Standard.setBoard(self, loc, player, value)
        elif self.gameType == 'DECIMAL':
            return Decimal.setBoard(self, loc, player, value)

    # Implemented Simple Random choice for Computer oponent
    def getRandomLocation(self):
        while True:
            choice = random.randint(0, 8)
            if self.board[choice] == '-':
                return choice

    def getRandomChoice(self):
        while True:
            choice = random.choice([2, 4, 6, 8])
            if choice not in self.board:
                return choice

    # minmax algorithm should be implemented to let Computer never lose
    # https://levelup.gitconnected.com/mastering-tic-tac-toe-with-minimax-algorithm-3394d65fa88f
    # https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/
    # https://www.youtube.com/watch?v=trKjYdBASyQ

    # def bestChoice(self):
    #     bestValue = float('-inf')
    #     curValue = 0
    #     for i in range(9):
    #         if self.board[i] == '-':
    #             # self.board[i] = 'O'
    #             score = self.minimax(0, True)
    #             # self.board[i]='-'
    #             if score > bestValue:
    #                 bestValue = score
    #                 return i
    #     return -1

    # def minimax(self, depth=0, isMax=True):
    #     if self.gameType == 'STANDARD':
    #         Standard.isWin()
    #     else:
    #         Decimal.isWin()
    #     if isMax:
    #         bestValue = float('-inf')
    #         for i in range(9):
    #             if self.board[i] == '-':
    #                 bestValue = max(self.minimax(depth+1, False), bestValue)
    #         return bestValue
    #     else:
    #         bestValue = float('inf')
    #         for i in range(9):
    #             if self.board[i] == '-':
    #                 bestValue = min(self.minimax(depth+1, True), bestValue)
    #         return bestValue


class Game(Human, Computer):
    def setBoard(self, loc, player, value='X'):
        if self.oponent == 'HUMAN':
            return Human.setBoard(self, loc, player, value)
        else:
            return Computer.setBoard(self, loc, player, value)

    def handleInput(self, player):
        tern = -1
        value = 0
        if self.player2 == player and self.oponent == 'COMPUTER':
            print('\nCOMPUTER Move :')
            tern = self.getRandomLocation()
            # tern = self.bestChoice()
            value = self.getRandomChoice()
        else:
            try:
                tern = int(
                    input(player + " Your tern, please choose your box: "))
            except ValueError or TypeError:
                tern = -1
            if self.gameType == 'DECIMAL':
                try:
                    value = int(
                        input(player + " Your tern, please choose value for box: "))
                except ValueError or TypeError:
                    value = 0
        return tern, value

    def checkResult(self, palyer):
        if self.gameType == 'STANDARD':
            if self.player1 == palyer:
                return 1 if Standard.isWin(self) else 0
            if self.player2 == palyer:
                return 2 if Standard.isWin(self, value='O') else 0
        else:
            if self.player1 == palyer:
                return 1 if Decimal.isWin(self) else 0
            if self.player2 == palyer:
                return 2 if Decimal.isWin(self, value='2') else 0

    def letsPlay(self):
        i = 0
        print(self)
        while i < 9:
            value = 0
            player = self.player1 if (i % 2 == 0) else self.player2
            i += 1
            tern, value = self.handleInput(player)
            retValue = self.setBoard(tern, player, value)
            if not retValue:
                i -= 1
                continue
            print(self)
            if i > 4:
                if self.checkResult(player) == 0:
                    continue
                else:
                    return
        print("Match Tie!!!")


if __name__ == "__main__":
    gameType = 'STANDARD'
    player2 = 'COMPUTER'

    choice = input("Do you want to play Default(Yes/No): ")
    if choice == 'yes':
        # st = Game()
        st = Game(oponent='COMPUTER')
        # st = Game(gameType='DECIMAL')
        # st = Game(gameType='DECIMAL',oponent='COMPUTER')
    else:
        player1 = input("Please Give the First Player Name: ")
        choice = input(
            "Do you want to play with Computer(Yes/No): ")
        if choice == 'yes':
            player2 = 'COMPUTER'
            oponent = 'COMPUTER'
            choice = input(
                "Please Select the game Type (STANDARD/DECIMAL): ")
            gameType = 'DECIMAL' if choice == 'DECIMAL' else 'STANDARD'
        else:
            oponent = 'HUMAN'
            player2 = input("Please Give the Second Player Name: ")
            choice = input(
                "Please Select the game Type (STANDARD/DECIMAL): ")
            gameType = 'DECIMAL' if choice == 'DECIMAL' else 'STANDARD'
        st = Game(player1, player2, gameType, oponent)
    st.letsPlay()
