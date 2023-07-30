abstract class Product {
  abstract getPrice(): number;
  abstract getParent(): Product | null;
  abstract setParent(parent: Product | null): void;
}

class SomeProduct1 implements Product {
  private price: number = 10;
  private parent: Product | null = null;

  getPrice(): number {
    return this.price;
  }

  getParent(): Product | null {
    return this.parent;
  }

  setParent(parent: Product | null): void {
    this.parent = parent;
  }
}

class SomeProduct2 implements Product {
  private price: number = 5;
  private parent: Product | null = null;

  getPrice(): number {
    return this.price;
  }

  getParent(): Product | null {
    return this.parent;
  }

  setParent(parent: Product | null): void {
    this.parent = parent;
  }
}

class Box implements Product {
  private price: number = 1;
  private parent: Product | null = null;
  private products: Product[] = [];

  getPrice(): number {
    let total = this.price;

    for (const product of this.products) {
      total += product.getPrice();
    }

    return total;
  }

  addProduct(product: Product): void {
    this.products.push(product);
    product.setParent(this);
  }

  removeProduct(product: Product): void {
    const index = this.products.indexOf(product);

    if (index >= 0) {
      this.products.splice(index, 1);
      product.setParent(null);
    }
  }

  getParent(): Product | null {
    return this.parent;
  }

  setParent(parent: Product | null): void {
    this.parent = parent;
  }
}

function main() {
  const myBox = new Box();

  for (let i = 0; i < 10; i++) {
    let myNewBox: Box;
    const random = Math.floor(Math.random() * 4);

    switch (random) {
      case 0:
        myBox.addProduct(new SomeProduct1());
        break;
      case 1:
        myBox.addProduct(new SomeProduct2());
        break;
      case 2:
        myNewBox = new Box();
        myNewBox.addProduct(new SomeProduct1());
        myBox.addProduct(myNewBox);
        break;
      case 3:
        myNewBox = new Box();
        myNewBox.addProduct(new SomeProduct2());
        myBox.addProduct(myNewBox);
        break;
    }
  }

  console.log(myBox.getPrice());
}

main();
