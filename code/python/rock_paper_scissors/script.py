import sys, random

if len(sys.argv) < 2:
    print("No choice specified, exiting.", file=sys.stderr)
    sys.exit(1)

u_choice = sys.argv[1].lower()

if u_choice != "rock" and u_choice != "paper" and u_choice != "scissors":
    print(f"Invalid choice \"{u_choice}\". Valid choices are \"rock\", "
        "\"paper\" and \"scissors\". (All case-insensitive), exiting.",
        file=sys.stderr)
    sys.exit(1)

c_choice = random.choice(["rock", "paper", "scissors"])

print(f"User: {u_choice}")
print(f"Computer: {c_choice}")

if c_choice == u_choice:
    print("Tie!")
elif ((c_choice == "rock" and u_choice == "paper")
    or (c_choice == "paper" and u_choice == "scissors")
    or (c_choice == "scissors" and u_choice == "rock")):
    print("Winner: User!")
else:
    print("Winner: Computer!")

