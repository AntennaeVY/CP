function createCube(size: number) {
  let cube = "";

  for (let i = 1; i <= size; i++) {
    cube += (`/\\`).repeat(i).padStart(size + i);
    cube += (`_\\`).repeat(size) + `\n`;
  }

  for (let i = size; i >= 1; i--) {
    cube += (`\\/`).repeat(i).padStart(size + i);
    cube += (`_/`).repeat(size) + `\n`;
  }

  return cube.slice(0, -1);
}
