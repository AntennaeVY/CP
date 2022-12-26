function executeCommands(commands) {
  let cpu = [0, 0, 0, 0, 0, 0, 0, 0];

  let cmd = {
    MOV: (x, i) => {
      x[0] = x[0][0] == 'V' ? cpu[+x[0].at(-1)] : x[0];
      cpu[+x[1].at(-1)] = +x[0] % 256;
    },
    ADD: (x, i) => {      
      cpu[+x[0].at(-1)] += cpu[+x[1].at(-1)];
      cpu[+x[0].at(-1)] %= 256;
    },
    DEC: (x, i) => {
      cpu[+x[0].at(-1)] -= 1 - 256;
      cpu[+x[0].at(-1)] %= 256;
    },
    INC: (x, i) => {
      cpu[+x[0].at(-1)] += 1;
      cpu[+x[0].at(-1)] %= 256;
    },
    JMP: (x, i) => {
      if (cpu[0]) {
        commands.splice(i+1, 0, ...commands.slice(+x[0], i));
        commands.splice(i+1 + (i - +x[0]), 0, `JMP ${i+1}`);
      }
    }
  }   

  for(let i=0; i < commands.length; i++) {
    let c = commands[i].split(" ");
    cmd[c[0]](c[1].split(","), i);
  }

  return cpu;
}
