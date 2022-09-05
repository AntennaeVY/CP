class TreeFactory {
  static treeTypes: TreeType[] = [];

  static getTreeType(color: string, texture: string): TreeType {
    let type = this.treeTypes.find(
      (t) => t.color == color && t.texture == texture
    );

    if (!type) {
      type = new TreeType(color, texture);
      this.treeTypes.push(type);
    }

    return type;
  }
}

class TreeType {
  color: string;
  texture: string;

  constructor(color: string, texture: string) {
    this.color = color;
    this.texture = texture;
  }
}

class Tree {
  name: string;
  x: number;
  y: number;
  type: TreeType;

  constructor(name: string, x: number, y: number, type: TreeType) {
    this.name = name;
    this.x = x;
    this.y = y;
    this.type = type;
  }
}

class Forest {
  private trees: Tree[] = [];

  plantTree(
    x: number,
    y: number,
    name: string,
    color: string,
    texture: string
  ): void {
    let type = TreeFactory.getTreeType(color, texture);
    this.trees.push(new Tree(name, x, y, type));
  }

  draw(canvas: any): void {
    for (let tree of this.trees) {
      console.log(tree);
    }
  }
}

function main() {
  const myForest = new Forest();
  myForest.plantTree(0, 0, "Caoba", "green", "green.png");
  myForest.plantTree(1, 1, "Acacia", "green", "green.png");

  myForest.draw("mycanvas.file");
}

main();
