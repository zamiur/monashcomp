def line(sx, sy, tx, ty):
        points_in_line = []
        dx = abs(tx - sx)
        dy = abs(ty - sy)
        x, y = sx, sy
        sx = -1 if sx > tx else 1
        sy = -1 if sy > ty else 1
        if dx > dy:
            err = dx / 2.0
            while x != tx:
                points_in_line.append((x, y))
                err -= dy
                if err < 0:
                    y += sy
                    err += dx
                x += sx
        else:
            err = dy / 2.0
            while y != ty:
                points_in_line.append((x, y))
                err -= dx
                if err < 0:
                    x += sx
                    err += dy
                y += sy
        points_in_line.append((x, y))
        return points_in_line

def main():
    line()%(input(),input(),input(),input())
