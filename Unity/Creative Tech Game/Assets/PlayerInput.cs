using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerInput : MonoBehaviour
{
    public float horizontalMove = 0.0f;
    public float speed = 40f;
    public characterController2D controller;
    private bool isJump = false;
    // Update is called once per frame
    void Update()
    {
        horizontalMove = (Input.GetAxisRaw("Horizontal"));
        if (Input.GetButtonDown("Jump"))
        {
            isJump = true;
        }
    }

    void FixedUpdate()
    {
        controller.Move(speed * horizontalMove * Time.fixedDeltaTime, false, isJump);
        isJump = false;
    }
}
