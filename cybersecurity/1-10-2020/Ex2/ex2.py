import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--x1", type = int)
parser.add_argument("--x2", type = int)
parser.add_argument("--y", type = int)
args = parser.parse_args()

if args.y == 0:
	print(args.x1 + args.x2)
elif args.y == 1:
	print(args.x1 - args.x2)
elif args.y == 2:
	print(args.x1 * args.x2)
elif args.y == 3:
	print(args.x1 // args.x2)
else:
	print("Invalid operation")
