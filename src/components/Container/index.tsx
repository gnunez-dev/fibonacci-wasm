import {useState} from 'react'
import FibonacciSequence from '../Fibonacci'
import './style.css'


const Container = (): JSX.Element => {
  return (
    <div className='con__container'>
      <h1 className='con__title'>Fibonacci - Wasm</h1>
      <section className='con__content'>
        <FibonacciSequence/>
      </section>
    </div>
  )
}
export default Container