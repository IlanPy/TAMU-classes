import argparse

def cmdargs():
    parser = argparse.ArgumentParser(description='create cones.')
    parser.add_argument('--benchfile', '-b', metavar='BENCH', type=str, required=True,
                        help='path to .bench file')
    args = parser.parse_args()

    return args


if __name__ == '__main__':
    args = cmdargs()
    print(args.benchfile)